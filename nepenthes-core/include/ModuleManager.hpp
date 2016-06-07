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

/* $Id: ModuleManager.hpp 2043 2005-10-04 15:59:52Z common $ */

#ifndef HAVE_MODULEMANAGER_HPP
#define HAVE_MODULEMANAGER_HPP

#include <string>
#include <list>

#include "Manager.hpp"

using namespace std;

#define MODULE_IFACE_VERSION 1

namespace nepenthes
{
	class Nepenthes;
	class Module;

	/**
	 * the ModuleManager takes care of loading all modules at runtime 
	 * and providing the module config file.
	 */
    class ModuleManager :public Manager
    {
    public:
        ModuleManager(Nepenthes *nepenthes);
        virtual ~ModuleManager();
        bool Init();
        bool Exit();
        virtual bool registerModule(string *modulepath, string *configpath);
        virtual bool unregisterModule(string *modulename);
		void doList();
    private:
        list <Module *> m_Modules;

    };

}

#endif
