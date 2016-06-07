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

 /* $Id: CSendDownloadHandler.hpp 1926 2005-08-27 20:52:47Z dp $ */

#ifndef HAVE_CSENDDOWNLOADHANDLER_HPP
#define HAVE_CSENDDOWNLOADHANDLER_HPP

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
	class CSendDialogue;

	class CSendDownloadHandler : public Module , public DownloadHandler , DialogueFactory
	{
	public:
		CSendDownloadHandler(Nepenthes *);
		~CSendDownloadHandler();

		bool Init();
		bool Exit();

		bool download(Download *down);

		Dialogue *createDialogue(Socket *socket);
	private:
		list <CSendDialogue *> m_Downloads;

	protected:
		uint32_t m_MaxFileSize;
		uint32_t m_ConnectTimeout;

	};


	

}
extern nepenthes::Nepenthes *g_Nepenthes;
#endif
