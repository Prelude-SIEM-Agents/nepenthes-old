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

/* $Id: Responder.hpp 1410 2007-10-12 13:07:23Z common $ */

#ifndef HAVE_RESPONDER_H
#define HAVE_RESPONDER_H

#include <stdint.h>

namespace nepenthes
{

    class Responder
    {
    public:
		virtual ~Responder() {};
        virtual bool doRespond(char *msg, uint32_t len)=0;
		virtual bool doRespond(const char *msg, uint32_t len)=0;

    };

}

#endif
