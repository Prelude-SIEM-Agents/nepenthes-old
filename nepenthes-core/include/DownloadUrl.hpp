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

/* $Id: DownloadUrl.hpp 2051 2005-10-05 16:46:29Z common $ */

#ifndef HAVE_DOWNLOADURL_HPP
#define HAVE_DOWNLOADURL_HPP


#include <string>

using namespace std;


namespace nepenthes
{


	/**
	 * protocoll/port mapping for various protocols
	 */
	typedef struct portTable
	{
		const char      *protocolName;
		uint16_t         port;
	};


	/**
	 * the download url
	 * splits up a url in its parts
	 * you can query each part
	 */
	class DownloadUrl
	{
	public:

		DownloadUrl(char  *url);
		virtual ~DownloadUrl();
		bool 			checkUrl();

		virtual string          getProtocol();
		virtual string          getUser();
		virtual string          getPass();
		virtual string          getAuth();
		virtual string          getHost();
		

		virtual uint32_t    getPort();
		virtual string          getPath();
		virtual string          getFile();
		virtual string          getDir();
		virtual string          getAnchor();

		virtual void          	setProtocol(char *arg);
		virtual void          	setUser(char *arg);
		virtual void          	setPass(char *arg);
		virtual void        	setAuth(char *arg);
		virtual void			setHost(char *arg);
		virtual void			setHost(uint32_t host);
		

		virtual void			setPort(uint32_t i);
		virtual void          	setPath(char *arg);
		virtual void          	setFile(char *arg);
		virtual void          	setDir(char *arg);
		virtual void          	setAnchor(char *arg);


	protected:
		string          m_protocol;
		string          m_user;
		string          m_pass;
		string			m_auth;	// "user:pass"
		string          m_host;
		uint32_t    m_port;
		string          m_path;

		string          m_file;
		string          m_dir;
		string          m_anchor;
	};


}

#endif
