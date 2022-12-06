#include <iostream>

using std::cout;
using std::endl;

#include "infra/common/web/cpp-httplib/httplib.h"
#include "domain/virt/conn/connection.h"
#include "infra/common/json/json.hpp"

using namespace tf;

using json = nlohmann::json;

int test_main()
{
	cout << "client sandbox" << endl;

	virt::virtconnection virt_conn("http://162.25.2.38:7070");
	
	auto conn = virt_conn.getConnect();
	
	auto rsp = conn->Get("/service/sites");
	
	cout << rsp->body << endl;

	json data = json::parse(rsp->body);

	cout << data["errorCode"] << endl;
	cout << data["errorDes"] << endl;
	return 0;	
}

int main()
{
	return test_main();
}