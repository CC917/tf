#ifndef ZZZZ
#define ZZZZ

#include "domain/virt/login/login.h"
#include "domain/virt/site/site.h"
#include "domain/virt/vm/vm.h"
#include "domain/obj/obj.h"

using tf::virt::vm;

struct CollectVmsInfo
{
	void operator() () const
	{
		obj::getVmInst()->Initvm();
	}
};

#endif