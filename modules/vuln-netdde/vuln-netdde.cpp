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

 /* $Id: vuln-netdde.cpp 550 2006-05-04 10:25:35Z common $ */

#include <ctype.h>

#include "NETDDEDialogue.hpp"
#include "vuln-netdde.hpp"

#include "SocketManager.hpp"

#include "DownloadManager.hpp"
#include "LogManager.hpp"
#include "DialogueFactoryManager.hpp"


#include "Buffer.hpp"
#include "Buffer.cpp"

#include "Message.hpp"
#include "Message.cpp"

#include "ShellcodeManager.hpp"

#include "Config.hpp"

#ifdef STDTAGS 
#undef STDTAGS 
#endif
#define STDTAGS l_mod

using namespace nepenthes;


/**
 * as we may need a global pointer to our Nepenthes in our modules,
 * and cant access the cores global pointer to nepenthes
 * we have to use a own global pointer to nepenthes per module
 * we need this pointer for logInfo() etc
 */
Nepenthes *g_Nepenthes;

/**
 * The Constructor
 * creates a new NETDDEVuln Module, 
 * NETDDEVuln is an example for binding a socket & setting up the Dialogue & DialogueFactory
 * 
 * 
 * it can be used as a shell emu to allow trigger commands 
 * 
 * 
 * sets the following values:
 * - m_DialogueFactoryName
 * - m_DialogueFactoryDescription
 * 
 * @param nepenthes the pointer to our Nepenthes
 */
NETDDEVuln::NETDDEVuln(Nepenthes *nepenthes)
{
	m_ModuleName        = "vuln-netdde";
	m_ModuleDescription = "provides Factory & dialogues for the netdde vuln";
	m_ModuleRevision    = "$Rev: 550 $";
	m_Nepenthes = nepenthes;

	m_DialogueFactoryName = "NETDDE Factory";
	m_DialogueFactoryDescription = "creates netdde dialogues";

	g_Nepenthes = nepenthes;
}

NETDDEVuln::~NETDDEVuln()
{

}


/**
 * Module::Init()
 * 
 * binds the port, adds the DialogueFactory to the Socket
 * 
 * @return returns true if everything was fine, else false
 *         false indicates a fatal error
 */
bool NETDDEVuln::Init()
{
	m_ModuleManager = m_Nepenthes->getModuleMgr();

	int32_t timeout;
	int32_t port;
	try
	{
		port = 		m_Config->getValInt("vuln-netdde.port");
		timeout = 	m_Config->getValInt("vuln-netdde.accepttimeout");
	} catch ( ... )
	{
		logCrit("Error setting needed vars, check your config\n");
		return false;
	}

	m_Nepenthes->getSocketMgr()->bindTCPSocket(0,port,0,timeout,this);


	return true;
}

bool NETDDEVuln::Exit()
{
	return true;
}

/**
 * DialogueFactory::createDialogue(Socket *)
 * 
 * creates a new NETDDEVulnDialogue
 * 
 * @param socket the socket the DIalogue has to use, can be NULL if the Dialogue can handle it
 * 
 * @return returns the new created dialogue
 */
Dialogue *NETDDEVuln::createDialogue(Socket *socket)
{
/*
	switch(socket->getLocalPort())
	{
	case 139:
		return new SMBNameDialogue(socket);
	}
*/	
	return new NETDDEDialogue(socket);
//	return g_Nepenthes->getFactoryMgr()->getFactory("WinNTShell DialogueFactory")->createDialogue(socket);
}



extern "C" int32_t module_init(int32_t version, Module **module, Nepenthes *nepenthes)
{
	if (version == MODULE_IFACE_VERSION) {
        *module = new NETDDEVuln(nepenthes);
        return 1;
    } else {
        return 0;
    }
}
