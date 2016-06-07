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

 /* $Id: download-rcp.hpp 2260 2006-01-13 20:35:08Z common $ */

#ifndef HAVE_RCPDOWNLOADHANDLER_HPP
#define HAVE_RCPDOWNLOADHANDLER_HPP

#include "Module.hpp"
#include "ModuleManager.hpp"
#include "SocketManager.hpp"
#include "Nepenthes.hpp"
#include "DownloadHandler.hpp"
#include "DownloadManager.hpp"

#include "Dialogue.hpp"
#include "DialogueFactory.hpp"

using namespace std;

namespace nepenthes
{
	class RCPDialogue;

	class RCPDownloadHandler : public Module , public DownloadHandler
	{
	public:
		RCPDownloadHandler(Nepenthes *);
		~RCPDownloadHandler();

		bool Init();
		bool Exit();

		bool download(Download *down);

	protected:
		uint32_t m_MaxFileSize;
		uint32_t m_ConnectTimeout;

	};


	

}
extern nepenthes::Nepenthes *g_Nepenthes;
#endif
