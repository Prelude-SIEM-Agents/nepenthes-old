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

 /* $Id: sqlhandler-postgres.hpp 904 2007-02-15 22:32:17Z common $ */

#include "config.h"

//#define USE_SSL

#ifdef HAVE_POSTGRES
#include <libpq-fe.h>
#endif 

#include "Module.hpp"
#include "ModuleManager.hpp"
#include "Nepenthes.hpp"
#include "Dialogue.hpp"
#include "Socket.hpp"

#include "SQLHandler.hpp"
#include "SQLHandlerFactory.hpp"

#include "POLLSocket.hpp"
#include "POLLSocket.cpp"
#include "Socket.cpp"

#include "SQLResult.hpp"
#include "SQLResult.cpp"

#include "SQLQuery.hpp"
#include "SQLQuery.cpp"


#include "DNSCallback.hpp"


using namespace std;

namespace nepenthes
{

	class Buffer;
	class SQLCallback;


	class SQLHandlerFactoryPostgres : public Module , public SQLHandlerFactory
	{

	public:
		SQLHandlerFactoryPostgres(Nepenthes *nepenthes);
		~SQLHandlerFactoryPostgres();

		bool Init();
		bool Exit();

		SQLHandler * createSQLHandler(string server, string user, string passwd, string table, 
									  string options, SQLCallback *cb);

	};

#ifdef HAVE_POSTGRES
	class SQLHandlerPostgres : public SQLHandler , public POLLSocket, public DNSCallback
	{
	public:
		SQLHandlerPostgres(Nepenthes *nepenthes, string server, string user, string 
						   passwd, string table, string options, SQLCallback *cb);
		~SQLHandlerPostgres();

		static void defaultNoticeProcessor(void * arg, const char * message);



		/* SQLHandler */
		bool runQuery(SQLQuery *query);
		string escapeString(string *str);
		string escapeBinary(string *str);
		string unescapeBinary(string *str);

		/* POLLSocket */
		bool Init();
		bool Exit();

		bool wantSend();

		int32_t doSend();
		int32_t doRecv();
		int32_t getSocket();
		int32_t   getsockOpt(int32_t level, int32_t optname,void *optval,socklen_t *optlen);

		bool checkTimeout();
		bool handleTimeout();

		/* DNSCallback */
		bool dnsResolved(DNSResult *result);
		bool dnsFailure(DNSResult *result);

		/* other */
		void disconnected();
		void reconnect();
		void connected();

	private:
		PGconn *m_PGConnection;

		ConnStatusType				m_ConnStatusType;
		PostgresPollingStatusType	m_PollingStatusType;

		Nepenthes	*m_Nepenthes;

		bool 	m_LockSend;

		list <SQLQuery *> 	m_Queries;

		string m_RemoteHost;

		string m_PGServer;
		string m_PGTable;
		string m_PGUser;
		string m_PGPass;
		string m_PGOptions;

	};

	class PGSQLResult : public SQLResult
	{
	public:
		PGSQLResult(PGresult *res, string query, void *obj) : SQLResult(query,obj)
		{
			int i,j;
			for ( j = 0;  j < PQntuples(res); j++ )
			{
				map<string,string> foo;
				for ( i=0;i<PQnfields(res);i++ )
				{
					
					foo[PQfname(res,i)] = PQgetvalue(res, j, i);
//					printf(" adding %s %s\n",PQfname(res,i), PQgetvalue(res, j, i));
					
				}
				m_Result.push_back(foo);

			}
		}

		PGSQLResult(vector< map<string,string> > *result, string query, void *obj) : SQLResult(query,obj)
		{
			m_Result = *result;
		}

	};
#endif // HAVE_POSTGRES

}

extern nepenthes::Nepenthes *g_Nepenthes;
