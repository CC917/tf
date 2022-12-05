#include <iostream>

using std::cout;
using std::endl;

#include "l0-infra/common/web/cpp-httplib/httplib.h"

int main()
{
	cout << "client sandbox" << endl;

	httplib::Client cli("http://www.baidu.com");

	auto res = cli.Get("/");
	cout << "ret code = " << res->status << endl;
	cout << "ret body = " << res->body << endl;

	return 0;
}