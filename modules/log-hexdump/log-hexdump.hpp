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

/* $Id: log-hexdump.hpp 1357 2007-08-23 13:15:26Z common $ */

#include <stdio.h>
#include <string>
#include <stdint.h>

#include "Module.hpp"
#include "ModuleManager.hpp"
#include "SocketManager.hpp"
#include "DownloadManager.hpp"
#include "Nepenthes.hpp"
#include "EventHandler.hpp"
#include "EventHandler.cpp"

using namespace std;



namespace nepenthes
{

	class LogHexdump : public Module , public EventHandler
	{
	public:
		LogHexdump(Nepenthes *);
		~LogHexdump();
		bool Init();
		bool Exit();
		uint32_t handleEvent(Event *event);

	private:
		string m_HexdumpPath;

	};

}

extern nepenthes::Nepenthes *g_Nepenthes;
