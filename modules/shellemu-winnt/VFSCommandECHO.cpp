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

/* $Id: VFSCommandECHO.cpp 1947 2005-09-08 17:30:06Z common $ */ 

#include "VFSCommandECHO.hpp"
#include "VFSNode.hpp"
#include "VFSDir.hpp"
#include "Nepenthes.hpp"
#include "LogManager.hpp"
#include "VFS.hpp"

#ifdef STDTAGS 
#undef STDTAGS 
#endif
#define STDTAGS l_shell

using namespace nepenthes;
using namespace std;

VFSCommandECHO::VFSCommandECHO(VFSNode *parent,VFS *vfs)
{
	m_Name =	"echo";
	m_ParentNode = parent;
	m_Type = VFS_EXE;
	m_VFS = vfs;
}

VFSCommandECHO::~VFSCommandECHO()
{

} 

int32_t VFSCommandECHO::run(vector<string> *paramlist)
{
	m_VFS->getStdOut()->clear();
	vector<string>::iterator it;
	vector<string>	params = *paramlist;

	if (params.size() == 1)
	{
		if (params[0] == "on" || params[0] == "off")
			return 0;
	}

	for(it=params.begin();it!=params.end();it++)
	{
		logSpam(" param is %s \n",&*it->c_str());
		m_VFS->addStdOut(&*it);

		if (it != params.end())
		{
			string space = " ";
			m_VFS->addStdOut(&space);
		}

	}
	logSpam("stdout is %s \n",m_VFS->getStdOut()->c_str());
	return 0;
} 

