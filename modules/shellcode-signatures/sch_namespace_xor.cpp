/********************************************************************************
 *                              Nepenthes
 *                        - finest collection -
 *
 *
 *
 * Copyright (C) 2005  Paul Baecher & Markus Koetter
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 * 
 *             contact nepenthesdev@users.sourceforge.net  
 *
 *******************************************************************************/

/* $Id: sch_namespace_xor.cpp 499 2006-04-08 18:40:14Z common $ */


#include "sch_namespace_xor.hpp"

#include "Nepenthes.hpp"
#include "Message.hpp"

#include "LogManager.hpp"
#include "Utilities.hpp"

#include "parser.hpp"

#ifdef STDTAGS 
	#undef STDTAGS 
#endif
#define STDTAGS l_sc | l_hlr

using namespace nepenthes;

NamespaceXOR::NamespaceXOR(sc_shellcode *sc):NamespaceShellcodeHandler(sc)
{
}

NamespaceXOR::~NamespaceXOR()
{

}

sch_result NamespaceXOR::handleShellcode(Message **msg)
{
	logSpam("%s checking %i...\n",m_ShellcodeHandlerName.c_str(), (*msg)->getSize());

	char *shellcode = (*msg)->getMsg();
	uint32_t len = (*msg)->getSize();

	int32_t ovec[10 * 3];
	int32_t matchCount; 

// data before xor
	const char  *preMatch   =   NULL;
	uint32_t    preSize     =   0;


// decoder
	const char  *decoderMatch=  NULL;
	uint32_t    decoderSize =   0;



// key
	const char  *keyMatch   =   NULL;
	char        byteKey     =   0;
	uint32_t    intKey      =   0;
	uint32_t    keySize     =   0;


// 'data to xor' size
	const char  *sizeMatch  =   NULL;
	uint32_t    codeSize    =   0;


// data after xor
	const char  *postMatch  =   NULL;
	uint32_t    postSize    =   0;




	if ( (matchCount = pcre_exec(m_Pcre, 0, (char *) shellcode, len, 0, 0, (int *)ovec, sizeof(ovec)/sizeof(int32_t))) > 0 )
	{
		logSpam("MATCH %s  matchCount %i map_items %i \n",m_ShellcodeHandlerName.c_str(), matchCount, m_MapItems);
		int32_t i;
		for ( i=0; i < m_MapItems; i++ )
		{
			if (m_Map[i] == sc_none)
					continue;

			logSpam(" i = %i map_items %i , map = %s\n",i,m_MapItems, sc_get_mapping_by_numeric(m_Map[i]));
			const char *match = NULL;
			int matchSize = pcre_get_substring((char *) shellcode, (int *)ovec, (int)matchCount, i, &match);

			switch ( m_Map[i] )
			{

			case sc_pre:
				preMatch = match;
				preSize = matchSize;
				logSpam("sc_pre %i\n",matchSize);
				break;

			case sc_decoder:
				decoderMatch = match;
				decoderSize = matchSize;
				logSpam("sc_pcre %i\n",matchSize);
				break;


			case sc_size:
				sizeMatch = match;
				logSpam("sc_size %i\n",matchSize);
				switch ( matchSize )
				{
				case 4:
					codeSize = (uint32_t)*((uint32_t *)match);
                    break;

				case 2:
					codeSize = (uint32_t)*((uint16_t *)match);
					break;

				case 1:
					codeSize = (uint32_t)*((byte *)match);
					break;
				}
				logSpam("\tnumeric %i\n",codeSize);
				break;


			case sc_sizeinvert:
				logSpam("sc_sizeinvert %i\n",matchSize);
				sizeMatch = match;
				switch ( matchSize )
				{
				case 4:
					codeSize = 0 - (uint32_t)*((uint32_t *)match);
					break;

				case 1:
					codeSize = 256 - (uint32_t)*((byte *)match);
					break;
				}
				logSpam("\tnumeric %i\n",codeSize);
				break;

			case sc_key:
				logSpam("sc_key %i\n",matchSize);
				keyMatch = match;
				keySize = matchSize;
				switch ( matchSize )
				{
				case 1:
					byteKey = *((byte *)match);
					logSpam("\tnumeric %1x\n",(unsigned int)byteKey);
					break;

				case 4:
                    intKey = *((uint32_t *)match);
					logSpam("\tnumeric %x\n",(unsigned int)intKey);
					break;

				}
				break;

			case sc_post:
				logSpam("sc_post %i\n",matchSize);
				postMatch = match;
				postSize = matchSize;
				break;


			default:
				logCrit("%s not used mapping %s\n",m_ShellcodeHandlerName.c_str(), sc_get_mapping_by_numeric(m_Map[i]));
			}
		}


// create buffer for decoding part of the message
		byte *decodedMessage = (byte *)malloc(postSize);
		memcpy(decodedMessage, postMatch, postSize);

		switch ( keySize )
		{
		case 1:
			if ( codeSize > postSize )
				logWarn("codeSize (%i) > postSize (%i), maybe broken xor?\n",codeSize,postSize);

			for ( uint32_t j = 0; j < codeSize && j < postSize; j++ )
				decodedMessage[j] ^= byteKey;
			break;

		case 4:
			if ( codeSize*4 > postSize )
				logWarn("codeSize*4 (%i) > postSize (%i), maybe broken xor?\n",codeSize*4,postSize);

			for ( uint32_t j = 0; j < codeSize && (j+1)*4 < postSize; j++ )
				*(uint32_t *)(decodedMessage+(j*4) ) ^= intKey;
			break;
		}

		char *newshellcode = (char *)malloc(len*sizeof(char));
		memset(newshellcode,0x90,len);

// create the same message with stripped xor decoder

		// the pre section
		memcpy(newshellcode                         ,preMatch       ,preSize);

		// the xor as 0x90 
		memset(newshellcode+preSize                 ,0x90           ,decoderSize);

		// the xor decoded data
		memcpy(newshellcode+preSize+decoderSize     ,decodedMessage ,postSize);

//		g_Nepenthes->getUtilities()->hexdump(l_crit,(byte *)newshellcode, len);			

		Message *newMessage = new Message((char *)newshellcode, len, (*msg)->getLocalPort(), (*msg)->getRemotePort(),
										  (*msg)->getLocalHost(), (*msg)->getRemoteHost(), (*msg)->getResponder(), (*msg)->getSocket());

		delete *msg;

		*msg = newMessage;

		free(decodedMessage);
		free(newshellcode);

		pcre_free_substring(preMatch);
		pcre_free_substring(decoderMatch);
		pcre_free_substring(keyMatch);
		pcre_free_substring(sizeMatch);
		pcre_free_substring(postMatch);

		return SCH_REPROCESS;
	}

	return SCH_NOTHING;
}




