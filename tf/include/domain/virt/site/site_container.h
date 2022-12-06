#ifndef SITE_MANAGER_H
#define SITE_MANAGER_H

#include "domain/virt/site/site.h"

#include <vector>

using site_container = std::vector<tf::virt::site>;

site_container sites;

site_container getsite_container()
{}

#endif