
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

/* $Id: sch_generic_unicode.hpp 2143 2005-11-03 15:15:44Z common $ */

#ifndef HAVE_GENERICUNICODE_HPP
#define HAVE_GENERICUNICODE_HPP

#include <stdint.h>
#include "ShellcodeHandler.hpp"


namespace nepenthes
{
	class GenericUniCode : public ShellcodeHandler
	{
	public:
		GenericUniCode(ShellcodeManager *shellcodemanager);
		~GenericUniCode();
		sch_result handleShellcode(Message **msg);

		uint32_t unicodeLength(uint8_t *unicode, uint32_t len);
		uint32_t unicodeTryDecode(uint8_t *unicode, uint32_t len, uint8_t **decoded, uint32_t *decodedLength);

		bool Init();
		bool Exit();
	};
}

#endif
