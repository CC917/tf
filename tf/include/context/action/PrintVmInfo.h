#ifndef PRINTINFO
#define PRINTINFO

#include <iostream>
#include "domain/virt/login/login.h"
#include "domain/virt/site/site.h"
#include "domain/virt/vm/vm.h"
#include "domain/obj/obj.h"

struct PrintVmInfo
{
	void operator() () const
	{
		obj::getVmInst()->dump();
	}
};

#endif