#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <iostream>
#include "domain/virt/conn/connection.h"

using tf::virt::virtconnection;

struct login
{
	std::string X_Token;
	
	login()
	{
		
	}
	
	void LogIn(std::string user,std::string password,virtconnection* conn)
	{
		auto conn_inst = conn->getConnect();
	
		httplib::Headers headers = {
			{"Accept","application/json;version=8.0.1"},
			{"Content-Type","application/json"},
			{"X-Auth-User",user.c_str()},
			{"X-Auth-Key",password.c_str()},
			{"X-Auth-AuthType","0"},
			{"X-Auth-UserType","0"},
			{"X-ENCRIPT-ALGORITHM","1"}
		};
	
		auto rsp = conn_inst->Post("/service/session",headers);

		X_Token = rsp->get_header_value("X-Auth-Token");
		
		if (X_Token == "") {
			std::cout <<rsp->body;
		}
	}
	
	std::string GetAuthToken()
	{
		return X_Token;
	}
};

#endif