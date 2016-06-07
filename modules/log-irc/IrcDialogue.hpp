/********************************************************************************
 *                              Nepenthes
 *                        - finest collection -
 *
 *
 *
 * Copyright (C) 2005  Paul Baecher & Markus Koetter
 * Copyright (C) 2005  Georg Wicherski
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

 /* $Id: IrcDialogue.hpp 550 2006-05-04 10:25:35Z common $ */

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
	struct SocksHeader
	{
		unsigned char version;
		unsigned char command;
		uint16_t destPort;
		uint32_t destAddress;
		char user[1024];

	};


	enum IrcDialogueState
	{
		IRCDIA_REQUEST_SEND,
		IRCDIA_CONNECTED,
	};

	class LogIrc;
	class Buffer;

	class IrcDialogue : public Dialogue
	{
	public:
		IrcDialogue(Socket *socket, LogIrc * logirc);
		~IrcDialogue();
		
		ConsumeLevel incomingData(Message * msg);
		ConsumeLevel outgoingData(Message * msg);
		ConsumeLevel handleTimeout(Message * msg);
		ConsumeLevel connectionLost(Message * msg);
		ConsumeLevel connectionShutdown(Message * msg);

		void logIrc(uint32_t mask, const char *message);

		void sendNick(bool random);
		void sendUser();
		void sendServerPass();
		
	protected:
		void processBuffer();
		void processLine(const char *line, uint32_t lineLength);
		
		void loggedOn();
		void processMessage(const char *origin, const char *target, const char *message);
		
		bool m_Pinged, m_LoggedOn;
		
		LogIrc 	*m_LogIrc;

		IrcDialogueState m_State;

		string 	m_NickName;

		Buffer 	*m_Buffer;
	};

}

