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

/* $Id: SubmitHandler.hpp 2043 2005-10-04 15:59:52Z common $ */

#ifndef HAVE_SUBMITHANDLER_HPP
#define HAVE_SUBMITHANDLER_HPP

#include <string>

using namespace std;

namespace nepenthes
{
	class Download;
	class SubmitManager;

	/**
	 * the SubmitHandler will get all the data a Download received, 
	 * and can do whatever he wants with it.
	 * store it, burn it ...
	 * so, if you are interested in all the malware which gets downloaded, 
	 * register as a SubmitHandler on the SubmitManager
	 */
	class SubmitHandler
    {
//	FileSubmitHandler(FileSubmitManager *pParent);
    public:
        virtual ~SubmitHandler(){};
        virtual void Submit(Download *down)=0;
		virtual void Hit(Download *down)=0;

		
		virtual string getSubmitterDescription()
		{
			return m_SubmitterDescription;
		}

		virtual string getSubmitterName()
		{
			return m_SubmitterName;
		}
    protected:
        SubmitManager *m_SubmitMgr;
		string			m_SubmitterName;
		string 			m_SubmitterDescription;
    };
}

#endif
