#ifndef ENUMSITE_H
#define ENUMSITE_H

#include "domain/virt/login/login.h"
#include "domain/virt/site/site.h"
#include "domain/virt/vm/vm.h"
#include "domain/obj/obj.h"

using tf::virt::site;

struct EnumSiteInfoAndSaveURI
{
	void operator() () const
	{
		site* site_inst = obj::getSiteInst();
		
		site_inst->InitURI();
	}
};

#endif