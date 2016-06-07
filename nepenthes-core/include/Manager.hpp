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

/* $Id: Manager.hpp 2043 2005-10-04 15:59:52Z common $ */

#ifndef HAVE_MANAGER_HPP
#define HAVE_MANAGER_HPP

namespace nepenthes
{

	class Nepenthes;

	/**
	 * a Manager wont do something in general, 
	 * a Manager will have Handlers working for him.
	 */
	class Manager
	{
	public:
		virtual ~Manager(){}; 
		virtual Nepenthes *getNepenthes();
		virtual bool Init()=0;
		virtual bool Exit()=0;
		virtual void doList()=0;
	protected:
		Nepenthes *m_Nepenthes;
	};
}

#endif
