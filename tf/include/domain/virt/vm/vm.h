#ifndef VM_H
#define VM_H

#include <string>
#include <iostream>
#include <vector>

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
		struct vm
		{	
			struct vm_node
			{
				
			};
		
			using vm_container = std::vector<vm_node>;
		
			vm(virtconnection* conn,login* login,site* site): _conn(conn),_login(login),_site(site)
			{
			}
			
			void Initvm()
			{
				auto conn_inst = _conn->getConnect();
	
				httplib::Headers headers = {
					{"Accept","application/json;version=8.0.1"},
					{"X-Auth-Token",_login->GetAuthToken().c_str()}
				};
	
				auto rsp = conn_inst->Get( _site->getURI() + "/vms",headers);

				data = json::parse(rsp->body);

				total = data["total"];
				
				//dump();
			}
			
			void dump()
			{
				int i = 0;
				for(auto c = data["vms"].begin();c!=data["vms"].end();c++) {
					cout << "############################################################\n";
					for(auto cc = c->begin();cc != c->end();cc++) {
						cout << cc.key() <<"  " <<cc.value() <<endl;
					}
					cout << "\n\n";
				}				
			}
			
			virtconnection* _conn;
			login* _login;

			site* _site;
			std::size_t total;
			vm_container ctr;
			
			json data;
		};
	}
}

#endif