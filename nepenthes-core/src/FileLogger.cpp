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

/* $Id: FileLogger.cpp 697 2006-11-11 09:17:19Z common $ */

#include <time.h>


#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include "FileLogger.hpp"
#include "Nepenthes.hpp"
#include "LogManager.hpp"

using namespace nepenthes;
using namespace std;


FileLogger::FileLogger(LogManager *lm) //: LogHandler(lm)
{
	m_Filename = 0;
	m_LogManager = lm;
}


FileLogger::~FileLogger()
{
	if( m_Filename != NULL)
		free(m_Filename);
	
}


void FileLogger::setLogFile(const char *filename)
{
	if( m_Filename != NULL)
		free(m_Filename);

	m_Filename = strdup(filename);
}


void FileLogger::log(uint32_t mask, const char *message)
{
	if( !m_Filename ) // remain silent until we get a log dest.
		return;

	FILE *f;

	if( !(f = fopen(m_Filename, "a")) )
		return;

	struct tm       t;
	time_t          stamp;
	time(&stamp);

#ifdef WIN32
	struct tm *pt =localtime(&stamp);
	memcpy(&t,pt,sizeof(struct tm));
#else
	localtime_r(&stamp, &t);
#endif


	string tag = "";
	for ( uint32_t i = 0; i < MAX_TAGS; i++ )
		if ( (1 << i) & mask  ) 
		{
			tag += " ";
			tag += m_LogManager->getTagName(i);
		}

    fprintf(f, "[%02d%02d%04d %02d:%02d:%02d%s] %s", t.tm_mday, t.tm_mon + 1, t.tm_year + 1900,
			 t.tm_hour, t.tm_min, t.tm_sec, tag.c_str(), message);

	fclose(f);
}


bool FileLogger::setOwnership(uid_t uid, gid_t gid)
{
#if !defined(CYGWIN) && !defined(CYGWIN32) && !defined(__CYGWIN__) && !defined(__CYGWIN32__) && !defined(WIN32)
	if ( m_Filename == NULL )
		return true;

	struct stat s;
	int32_t filestat = stat(m_Filename, &s);

	if ( filestat != 0 )
	{
		if ( errno == ENOENT )
		{
			logInfo("Creating logfile %s\n",m_Filename);
			FILE *f = fopen(m_Filename,"w");
			if (f == NULL)
			{
				logCrit("Logfile %s does not exist, creating failed with %s\n", m_Filename,strerror(errno));
				return false;
			}
			fclose(f);
		}
		else
		{
			logCrit("Could not access logfile %s: %s\n", m_Filename, strerror(errno));
			return false;
		}
	}

	if( s.st_uid != uid || s.st_gid != gid )
	{
		if ( chown(m_Filename, uid, gid) != 0 )
		{
			logCrit("Failed to change ownership for file %s: %s\n", m_Filename, strerror(errno));
			return false;
		}

		logInfo("Logfile %s ownership is now %d:%d (%s:%s)\n", m_Filename, uid, gid, getpwuid(uid)->pw_name,
			getgrgid(gid)->gr_name);
	}
#endif

	return true;
}


