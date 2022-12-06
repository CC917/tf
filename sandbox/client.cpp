#include <iostream>

using std::cout;
using std::endl;

#include "infra/common/web/cpp-httplib/httplib.h"
#include "domain/virt/conn/connection.h"

using namespace tf;

int main()
{
	cout << "client sandbox" << endl;

	virt::virtconnection virt_conn("");
	
	auto conn = virt_conn.getConnect();
	
	auto rsp = conn->Get("");
	
	cout << rsp->body << endl;

	return 0;
}