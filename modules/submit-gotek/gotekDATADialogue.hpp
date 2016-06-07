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

 /* $Id: gotekDATADialogue.hpp 379 2006-03-13 17:20:51Z oxff $ */

#include "DialogueFactory.hpp"
#include "Module.hpp"
#include "ModuleManager.hpp"
#include "SocketManager.hpp"
#include "Nepenthes.hpp"
#include "Dialogue.hpp"
#include "Socket.hpp"
#include "DNSCallback.hpp"

using namespace std;

namespace nepenthes
{

	typedef enum 
	{
		GDATA_NULL,
		GDATA_AUTH,
		GDATA_DONE
	} gctrl_state;


	class Buffer;
	class GotekContext;

	class gotekDATADialogue : public Dialogue
	{
	public:
		gotekDATADialogue(GotekContext *ctx);
		~gotekDATADialogue();
		ConsumeLevel incomingData(Message *msg);
		ConsumeLevel outgoingData(Message *msg);
		ConsumeLevel handleTimeout(Message *msg);
		ConsumeLevel connectionLost(Message *msg);
		ConsumeLevel connectionShutdown(Message *msg);

		void setSocket(Socket * socket) { m_Socket = socket; }
		bool loadFile();

	protected:
		Buffer		* m_Buffer;
		gctrl_state	m_State;

		GotekContext *	m_GotekContext;
		unsigned char *	m_FileBuffer;
	};
}
