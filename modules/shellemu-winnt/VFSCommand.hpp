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

 /* $Id: VFSCommand.hpp 1927 2005-08-27 21:56:59Z dp $ */

#ifndef HAVE_VFSCOMMANDECHO
#define HAVE_VFSCOMMANDECHO

#include <list>
#include <string>
#include <vector>

#include "VFSNode.hpp"

using namespace std;

namespace nepenthes
{
	class VFSDir;
	class VFS;

    class VFSCommand : public VFSNode
	{
	public:
//        virtual ~VFSCommand(){};
//		virtual int32_t run(string *params, VFSDir *dir)=0;
		virtual int32_t run(vector<string> *paramlist)=0;
	protected:
		VFS		*m_VFS;
	};

}

#endif
