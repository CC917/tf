#ifndef LoginAnd_H
#define LoginAnd_H

#include <iostream>
#include "domain/virt/login/login.h"
#include "domain/virt/site/site.h"
#include "domain/virt/vm/vm.h"
#include "domain/obj/obj.h"

struct LoginAndSaveToken
{
	void operator() () const
	{
		login *login_inst = obj::getLoginInst();
		
		login_inst->LogIn("admin","b30039456!",obj::virt_conn);
	
		obj::XToken = login_inst->GetAuthToken();
	}
};

#endif