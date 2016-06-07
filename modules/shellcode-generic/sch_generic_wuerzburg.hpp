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

 /* $Id: sch_generic_wuerzburg.hpp 1700 2005-07-26 21:19:44Z dp $ */

#ifndef HAVE_LSASS_WUERZBURG_HPP
#define HAVE_LSASS_WUERZBURG_HPP

#include <pcre.h>
#include "ShellcodeHandler.hpp"


namespace nepenthes
{
	class Wuerzburg : public ShellcodeHandler
	{
	public:
		Wuerzburg(ShellcodeManager *shellcodemanager);
		~Wuerzburg();
		sch_result handleShellcode(Message **msg);
		bool Init();
		bool Exit();
	protected:
		pcre *m_wuerzburgPattern;
	};
}

#endif
