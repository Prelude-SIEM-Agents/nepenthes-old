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

/* $Id: Dialogue.hpp 2043 2005-10-04 15:59:52Z common $ */

#ifndef HAVE_DIALOGUE_HPP
#define HAVE_DIALOGUE_HPP

#include <string>
using namespace std;

namespace nepenthes
{


    class Module;
    class Socket;
    class Nepenthes;
    class Message;

	/**
	 */
	typedef enum
	{
		CL_DROP,
		CL_UNSURE,
		CL_READONLY,
		CL_ASSIGN,
		CL_ASSIGN_AND_DONE
	} ConsumeLevel;



	/**
	 * whenever we want to interact with a Socket, we assign a Dialogue.
	 * the Dialogue implements the protocol the socket speaks
	 * multiple Dialogues can be assigned to a Socket
	 */
    class Dialogue
    {
    public:
        virtual ~Dialogue(){};
        virtual ConsumeLevel incomingData(Message * msg) = 0;
        virtual ConsumeLevel outgoingData(Message * msg) = 0;
        virtual ConsumeLevel handleTimeout(Message * msg) = 0;

		virtual ConsumeLevel connectionEstablished()
		{
			return m_ConsumeLevel;
		};      // getsockopt()  == EISCONN || == 0 && m_Socket->getState() == SS_CONNECTING
		
        virtual ConsumeLevel connectionLost(Message * msg) = 0;      // recv < 0
        virtual ConsumeLevel connectionShutdown(Message * msg) = 0;  // recv() == 0
        virtual ConsumeLevel getConsumeLevel()
		{
			return m_ConsumeLevel;
		}
        virtual void setConsumeLevel(ConsumeLevel cl)
		{
			m_ConsumeLevel = cl;
		}
        virtual string getDialogueName()
		{
			return m_DialogueName;
		};
        virtual string getDialogueDescription()
		{
			return m_DialogueDescription;
		};

		virtual Socket *getSocket()
		{
			return m_Socket;
		}


		/**
		 */
		virtual void dump()
		{// as some dialogues wont need this fn
			return;
		}

    protected:
        Module      *m_Module;
        Socket      *m_Socket;
        Nepenthes   *m_Nepenthes;

        ConsumeLevel m_ConsumeLevel;
        string      m_DialogueName;
        string      m_DialogueDescription;

    };

}
#endif
