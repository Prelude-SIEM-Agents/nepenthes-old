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

 /* $Id: LSASSDialogue.hpp 1952 2005-09-09 21:18:37Z common $ */


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
	typedef enum
	{
        LSASS_HOD_STAGE1,
		LSASS_HOD_STAGE2,
		LSASS_HOD_STAGE3,
		LSASS_HOD_STAGE4,
		LSASS_HOD_STAGE5,
		LSASS_HOD_STAGE6,
		LSASS_HOD_REST,

		LSASS_DONE

	} lsass_state;

	class Buffer;

	class LSASSDialogue : public Dialogue
	{
	public:
		LSASSDialogue(Socket *socket);
		~LSASSDialogue();
		ConsumeLevel incomingData(Message *msg);
		ConsumeLevel outgoingData(Message *msg);
		ConsumeLevel handleTimeout(Message *msg);
		ConsumeLevel connectionLost(Message *msg);
		ConsumeLevel connectionShutdown(Message *msg);
		void dump();

	protected:
		lsass_state m_State;
		Buffer		*m_Buffer;

	};
}
