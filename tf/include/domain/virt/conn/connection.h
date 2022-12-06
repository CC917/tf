#ifndef LOGGER_H
#define LOGGER_H

#include <string>

#include "infra/common/web/cpp-httplib/httplib.h"

namespace tf
{
	namespace virt
	{
		struct virtconnection
		{
			virtconnection(std::string address) : _address(address),_cli(address)
			{
			}
			
			~virtconnection() = default;
			
			httplib::Client* getConnect()
			{
				return &_cli;
			}

			std::string& getAddress()
			{
				return _address;
			}				
			
			std::string _address;
			
			httplib::Client _cli;
		};
	}
}


#endif