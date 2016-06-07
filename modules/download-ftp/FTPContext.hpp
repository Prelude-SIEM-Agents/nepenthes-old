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

 /* $Id: FTPContext.hpp 2001 2005-09-27 13:54:35Z common $ */

#include <stdint.h>
#include "DNSCallback.hpp"

namespace nepenthes
{
	class Download;
	class FILEDialogue;
	class CTRLDialogue;

	class FTPContext //: public DNSCallback
	{

	public:
		FTPContext(Download *down);
		FTPContext(Download *down, CTRLDialogue *dia);
		~FTPContext();

		void setActiveFTPBindPort(uint16_t port);
		uint16_t getActiveFTPBindPort();
		Download *getDownload();
		CTRLDialogue *getCTRLDialogue();

	protected:

		Download        *m_Download;

		CTRLDialogue    *m_CDialogue;

		uint16_t 	m_ActiveFtpBindPort;
	};

}
