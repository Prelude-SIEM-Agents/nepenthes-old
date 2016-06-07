/********************************************************************************
 *                              Nepenthes
 *                        - finest collection -
 *
 *
 *
 * Copyright (C) 2006 Niklas Schiffler <nick@digitician.eu> 
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

 /* $Id: submit-http.hpp 839 2007-02-06 16:54:31Z common $ */

#include <curl/curl.h>
#include <curl/types.h> /* new for v7 */
#include <curl/easy.h> /* new for v7 */

#include "Nepenthes.hpp"
#include "Module.hpp"
#include "SubmitHandler.hpp"
#include "EventHandler.hpp"
#include "Download.hpp"


using namespace std;

namespace nepenthes
{

	class HTTPSubmitHandler : public Module , public SubmitHandler, public EventHandler
	{
	public:
		HTTPSubmitHandler(Nepenthes *nep);
		~HTTPSubmitHandler();
		bool Init();
		bool Exit();

		void Submit(Download *down);
		void Hit(Download *down);

		uint32_t handleEvent(Event *event);

	protected:
		CURLM* m_CurlStack;
		int32_t m_Queued;
		string m_URL;
		string m_Email;
		string m_User;
		string m_Password;

	};

}

extern nepenthes::Nepenthes *g_Nepenthes;
