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
 
/* $Id: SQLResult.cpp 594 2006-07-29 18:51:55Z common $ */

#include <errno.h>
#include "SQLManager.hpp"
#include "SQLCallback.hpp"
#include "SQLResult.hpp"
#include "SQLResult.hpp"
#include "SQLHandler.hpp"

#include "Nepenthes.hpp"
#include "LogManager.hpp"

using namespace nepenthes;


SQLResult::SQLResult(string query, void *obj)
{
	logPF();
	m_Object = obj;
	m_Query = query;
}

SQLResult::~SQLResult()
{
	
}

string SQLResult::getQuery()
{
	return m_Query;
}

void *SQLResult::getObject()
{
	return m_Object;
}

vector< map<string,string> > *SQLResult::getResult()
{
	return &m_Result;
}
