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

 /* $Id: sch_generic_leimbach_url_xor.hpp 2274 2006-01-15 20:49:05Z common $ */

#ifndef HAVE_LEIMBACHURLXORXOR_HPP
#define HAVE_LEIMBACHURLXORXOR_HPP

#include <stdint.h>
#include <pcre.h>
#include "ShellcodeHandler.hpp"


namespace nepenthes
{
	class LeimbachUrlXORXOR : public ShellcodeHandler
	{
	public:
		LeimbachUrlXORXOR(ShellcodeManager *shellcodemanager);
		~LeimbachUrlXORXOR();
		sch_result handleShellcode(Message **msg);
		bool Init();
		bool Exit();
	protected:
        list <XORPcreContext *> m_Pcres;
	};
}

#endif
