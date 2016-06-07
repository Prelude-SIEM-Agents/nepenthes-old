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

 /* $Id: VFSFile.hpp 1927 2005-08-27 21:56:59Z dp $ */

#include <list>
#include <string>


#include "VFSNode.hpp"

using namespace std;

namespace nepenthes
{
	class Buffer;

	class VFSFile : public VFSNode
	{
	public:
		VFSFile(VFSNode *parentnode, char *name, char *data, uint32_t len);
		~VFSFile();
		virtual uint32_t addData(char *data,uint32_t len);
		virtual char *getData();
		virtual uint32_t getSize();
		void truncateFile();
	protected:
		int32_t m_Size;
		Buffer  *m_Buffer;

	};

}
