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

/* $Id: EventHandler.cpp 697 2006-11-11 09:17:19Z common $ */

#include "Event.hpp"
#include "EventHandler.hpp"
#include <time.h>


using namespace nepenthes;
/**
 * test if a EventHandler wants a specific Event 
 * 
 * @param event  the event to test
 * 
 * @return true if the EventHandler wants the Event
 *         else false
 */
bool EventHandler::testEvent(Event *event)
{
	return m_Events.test(event->getType());
};


/**
 * get the EventHandler's description
 * 
 * @return the EventHandlers description as string
 */
string EventHandler::getEventHandlerDescription()
{
	return m_EventHandlerDescription;
};


/**
 * get the EventHandler's name
 * 
 * @return the EventHandlers name as string
 */

string EventHandler::getEventHandlerName()
{
	return m_EventHandlerName;
};


/**
 * check if a EventHandler experienced a timeout
 * 
 * @return true if the EventHandler wants EV_TIMEOUT and he timed out 
 *         else false
 */
bool EventHandler::isTimeout()
{
	if ( m_Events.test(EV_TIMEOUT) && m_Timeout < time(NULL) )
		return true;
	return false;
};

