#ifndef OBJ_H
#define OBJ_H

#include <string>
#include "domain/virt/conn/connection.h"
#include "domain/virt/login/login.h"
#include "domain/virt/site/site.h"
#include "domain/virt/vm/vm.h"

using tf::virt::site;
using tf::virt::vm;

struct obj
{
	static void setConn(tf::virt::virtconnection& conn)
	{
		virt_conn = &conn;
	}
	
	static login* getLoginInst()
	{
		if (login_ == nullptr) {
			login_ = new login();
		}
		return login_;
	}

	static site* getSiteInst()
	{
		if (site_ == nullptr) {
			site_ = new site(virt_conn,login_);
		}
		return site_;
	}

	static vm* getVmInst()
	{
		if (vm_ == nullptr) {
			vm_ = new vm(virt_conn,login_,site_);
		}
		return vm_;
	}

	static login* login_;

	static tf::virt::virtconnection *virt_conn;
	
	static std::string XToken;

	static tf::virt::site *site_;
	
	static tf::virt::vm *vm_;
};

#endif