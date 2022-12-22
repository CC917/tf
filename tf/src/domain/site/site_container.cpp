#include "domain/virt/site/site_container.h"

namespace {
	site_container sites;	
}

site_container& getsite_container()
{
	return sites;
}