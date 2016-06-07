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
 
 /* $Id: shellcode-generic.hpp 1923 2005-08-27 18:10:01Z dp $ */

#include "Module.hpp"
#include "ModuleManager.hpp"
#include "SocketManager.hpp"
#include "Nepenthes.hpp"

#include "ShellcodeHandler.hpp"
#include <pcre.h>

using namespace std;

namespace nepenthes
{
	struct PcreContext
	{
		pcre *m_Pcre;
		string m_Name;
		uint16_t m_Offset; // we need this for agobot csend
	};



	class GenericShellcodeHandler : public Module
	{
	public:
		GenericShellcodeHandler(Nepenthes *);
		~GenericShellcodeHandler();
        bool Init();
		bool Exit();

	protected:
		list <ShellcodeHandler *> m_ShellcodeHandlers;
	};

}

extern nepenthes::Nepenthes *g_Nepenthes;
extern nepenthes::GenericShellcodeHandler *g_GenericShellcodeHandler;
