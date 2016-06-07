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

 /* $Id: vuln-pnp.hpp 1841 2005-08-15 14:48:03Z common $ */

 /* $Id: vuln-pnp.hpp 1841 2005-08-15 14:48:03Z common $ */

#include "DialogueFactory.hpp"
#include "Module.hpp"
#include "ModuleManager.hpp"
#include "SocketManager.hpp"
#include "Nepenthes.hpp"
#include "Dialogue.hpp"
#include "Socket.hpp"

using namespace std;

namespace nepenthes
{

	class ShellcodeHandler;

	class PNPVuln : public Module , public DialogueFactory
	{
	public:
		PNPVuln(Nepenthes *);
		~PNPVuln();
		Dialogue *createDialogue(Socket *socket);
		bool Init();
		bool Exit();
	protected:
		list <ShellcodeHandler *> m_ShellcodeHandlers;
	};



}
extern nepenthes::Nepenthes *g_Nepenthes;
