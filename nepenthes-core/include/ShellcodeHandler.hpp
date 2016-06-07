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

/* $Id: ShellcodeHandler.hpp 1644 2005-07-14 16:19:15Z dp $ */

#ifndef HAVE_SHELLCODEHANDLER_HPP
#define HAVE_SHELLCODEHANDLER_HPP

#include <string>

#include "ShellcodeManager.hpp"

using namespace std;

namespace nepenthes
{
	


	class ShellcodeHandler
	{
	public:
		virtual ~ShellcodeHandler(){};
		virtual sch_result  handleShellcode(Message **msg)=0;  
		virtual bool Init()=0;
		virtual bool Exit()=0;

		
		virtual string getShellcodeHandlerName()
		{
			return m_ShellcodeHandlerName;
		}

		virtual string getShellcodeHandlerDescription()
		{
			return m_ShellcodeHandlerDescription;
		}

		virtual ShellcodeManager *getShellcodeManager()
		{
			return m_ShellcodeManager;
		}

	protected:
		string              m_ShellcodeHandlerName;
		string              m_ShellcodeHandlerDescription;
		ShellcodeManager    *m_ShellcodeManager;
	};
}

#endif
