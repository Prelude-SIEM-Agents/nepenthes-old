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

/* $Id: FileLogger.hpp 664 2006-10-11 18:25:03Z dp $ */

#ifndef FILELOFFER_HPP
#define FILELOFFER_HPP

#include "LogHandler.hpp"

namespace nepenthes
{

	/**
	 * simple log handler for file output.
	 */
	class FileLogger : public LogHandler
	{
	public:
						FileLogger(LogManager *lm);
		virtual			~FileLogger();
		virtual void	log(uint32_t mask, const char *message);
		virtual void	setLogFile(const char *filename);
		virtual bool	setOwnership(uid_t uid, gid_t gid);

	private:
		char		*m_Filename;
	};

}

#endif
