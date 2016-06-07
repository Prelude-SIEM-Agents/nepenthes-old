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

 /* $Id: download-ftp.hpp 343 2006-02-20 17:11:57Z common $ */

#ifndef HAVE_DOWNLOAD_FTP_HPP
#define HAVE_DOWNLOAD_FTP_HPP

#include "DialogueFactory.hpp"
#include "Module.hpp"
#include "ModuleManager.hpp"
#include "SocketManager.hpp"
#include "Nepenthes.hpp"
#include "Dialogue.hpp"
#include "Socket.hpp"

#include "DownloadHandler.hpp"
#include "DNSCallback.hpp"

using namespace std;

namespace nepenthes
{

	class FTPContext;

	class FTPDownloadHandler : public Module , public DialogueFactory , public DownloadHandler , public DNSCallback
	{
	public:
		FTPDownloadHandler(Nepenthes *);
		~FTPDownloadHandler();
		Dialogue *createDialogue(Socket *socket);
		bool Init();
		bool Exit();

		bool download(Download *down);

		bool dnsResolved(DNSResult *result);
		bool dnsFailure(DNSResult *result);

		bool removeContext(FTPContext *context);

		uint16_t getMinPort();
		uint16_t getMaxPort();
		uint32_t getRetrAddress();
	protected:
		list <FTPContext *> m_Contexts;

		// we need those vars for NAT active ftp
		string	m_DynDNS;
		uint16_t m_MinPort;
		uint16_t m_MaxPort;
		uint32_t m_RetrAddress;
	};



}
extern nepenthes::Nepenthes *g_Nepenthes;
extern nepenthes::FTPDownloadHandler *g_FTPDownloadHandler;

#endif
