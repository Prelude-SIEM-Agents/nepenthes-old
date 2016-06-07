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

/* $Id: POLLSocket.hpp 1410 2007-10-12 13:07:23Z common $ */

#ifndef HAVE_POLLSOCKET_HPP
#define HAVE_POLLSOCKET_HPP

#include "Socket.hpp"
#include "Responder.hpp"


namespace nepenthes
{
	class Packet;

	class POLLSocket : public Socket
	{
public:
	POLLSocket();

	virtual ~POLLSocket() {};
		bool bindPort();
		bool Init();
		bool Exit();
		bool connectHost();
		Socket * acceptConnection();
		virtual bool wantSend();

		virtual int32_t doSend();
		virtual int32_t doRecv();
		int32_t doWrite(char *msg, uint32_t len);
		virtual bool checkTimeout();
		virtual bool handleTimeout();
		bool doRespond(char *msg, uint32_t len);
		bool doRespond(const char *msg, uint32_t len);

	};
}

#endif
