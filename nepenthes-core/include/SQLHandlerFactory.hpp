
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

/* $Id: SQLHandlerFactory.hpp 656 2006-10-08 15:00:19Z common $ */

#ifndef HAVE_SQLHANDLERFACTORY_HPP
#define HAVE_SQLHANDLERFACTORY_HPP

#include <string>

using namespace std;

namespace nepenthes
{
	class SQLHandler;
	class SQLCallback;


	class SQLHandlerFactory
	{
		public:
		virtual ~SQLHandlerFactory(){};
		virtual string getDBType()
		{
			return m_DBType;
		}

		virtual SQLHandler *createSQLHandler(string server, string user, string passwd, string table, string options, SQLCallback *cb)=0;
		
	protected:
		string m_SQLHandlerFactoryName;
		string m_DBType;
	};
}

#endif
