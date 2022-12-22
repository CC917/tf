#ifndef SITE_H
#define SITE_H

#include <string>
#include <iostream>

#include "domain/virt/conn/connection.h"
#include "domain/virt/login/login.h"
#include "infra/common/json/json.hpp"

using json = nlohmann::json;
using std::cout;
using std::endl;

namespace tf
{
	namespace virt
	{
		struct site
		{
			const std::string URI = "service/sites";
			
			site(virtconnection* conn,login* login): _conn(conn),_login(login)
			{
			}
			
			void InitURI()
			{
				auto conn_inst = _conn->getConnect();
	
				httplib::Headers headers = {
					{"Accept","application/json;version=8.0.1"},
					{"X-Auth-Token",_login->GetAuthToken().c_str()}
				};
	
				auto rsp = conn_inst->Get("/service/sites",headers);

				json data = json::parse(rsp->body);

				//find sites.
				for(auto c = data["sites"].begin();c!=data["sites"].end();c++) {
					//find site.
					for(auto cc = c->begin();cc != c->end();cc++) {
						if (cc.key() == "uri")
							URII = cc.value();
					}
				}
			}
			
			inline std::string getURI()
			{
				return URII;
			}
			
			virtconnection* _conn;
			login* _login;

			std::string URII;
		};
	}
}

#endif