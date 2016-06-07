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

/* $Id: DNSQuery.cpp 836 2007-02-06 15:16:50Z common $ */

#include "DNSQuery.hpp"

using namespace nepenthes;


DNSQuery::DNSQuery(DNSCallback *callback, char *dns, uint16_t querytype, void *obj)
{
	m_Callback = callback;
	m_DNS = dns;
	m_Object = obj;
	m_QueryType = querytype;
}

DNSQuery::~DNSQuery()
{
}

/**
 * get the DNSCallback
 * 
 * @return returns the DNSCallback assigned to the DNSQuery
 */
DNSCallback *DNSQuery::getCallback()
{
	return m_Callback;
}


/**
 * chancel the callback
 */
void DNSQuery::cancelCallback()
{
	m_Callback = NULL;
}

/**
 * get the dns to resolve
 * 
 * @return the domain to resolve as string
 */
string DNSQuery::getDNS()
{
	return m_DNS;
}

/**
 * check what type of result we got
 * 
 * @return returns the querytype
 *         either DNS_QUERY_A or
 *         DNS_QUERY_TXT
 */
uint16_t DNSQuery::getQueryType()
{
	return m_QueryType;
}

/**
 * get the additional data assigned to the DNSQuery
 * 
 * @return returns the additional datas pointer
 */
void *DNSQuery::getObject()
{
	return m_Object;
}
