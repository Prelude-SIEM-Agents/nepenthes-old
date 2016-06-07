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

 /* $Id: vuln-mssql.cpp 550 2006-05-04 10:25:35Z common $ */

#include <ctype.h>

#include "vuln-mssql.hpp"
#include "MSSQLDialogue.hpp"

#include "SocketManager.hpp"
#include "Message.hpp"
#include "DownloadManager.hpp"
#include "LogManager.hpp"
#include "DialogueFactoryManager.hpp"

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
 * creates a new MSSQLVuln Module, 
 * MSSQLVuln is an example for binding a socket & setting up the Dialogue & DialogueFactory
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
MSSQLVuln::MSSQLVuln(Nepenthes *nepenthes)
{
	m_ModuleName        = "vuln-mssql";
	m_ModuleDescription = "emulate the MS02-061 flaw";
	m_ModuleRevision    = "$Rev: 550 $";
	m_Nepenthes = nepenthes;

	m_DialogueFactoryName = "mssql Dialogue Factory";
	m_DialogueFactoryDescription = "creates dialogues for the MS02-061 flaw";

	g_Nepenthes = nepenthes;
}

MSSQLVuln::~MSSQLVuln()
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
bool MSSQLVuln::Init()
{
	m_ModuleManager = m_Nepenthes->getModuleMgr();

	int32_t timeout;
	int32_t port;
	try
	{
		port = m_Config->getValInt("vuln-mssql.port");
		timeout = m_Config->getValInt("vuln-mssql.accepttimeout");
	} catch ( ... )
	{
		logCrit("Error setting needed vars, check your config\n");
		return false;
	}

	m_Nepenthes->getSocketMgr()->bindUDPSocket(0,port,0,timeout,this);
	return true;
}

bool MSSQLVuln::Exit()
{
	return true;
}

/**
 * DialogueFactory::createDialogue(Socket *)
 * 
 * creates a new MSSQLVulnDialogue
 * 
 * @param socket the socket the DIalogue has to use, can be NULL if the Dialogue can handle it
 * 
 * @return returns the new created dialogue
 */
Dialogue *MSSQLVuln::createDialogue(Socket *socket)
{
	return new MSSQLDialogue(socket);
}





extern "C" int32_t module_init(int32_t version, Module **module, Nepenthes *nepenthes)
{
	if (version == MODULE_IFACE_VERSION) {
        *module = new MSSQLVuln(nepenthes);
        return 1;
    } else {
        return 0;
    }
}
