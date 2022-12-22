#include <iostream>

using std::cout;
using std::endl;

#include "infra/common/web/cpp-httplib/httplib.h"
#include "domain/virt/conn/connection.h"
#include "domain/virt/login/login.h"
#include "domain/virt/site/site.h"
#include "domain/virt/vm/vm.h"
#include "domain/obj/obj.h"

#include "context/action/LoginAndSaveToken.h"
#include "context/action/EnumSiteInfoAndSaveURI.h"
#include "context/action/CollectVmsInfo.h"
#include "context/action/PrintVmInfo.h"

int virt_main()
{	
	tf::virt::virtconnection virt_conn("http://162.25.2.38:7070");
	
	obj::setConn(virt_conn);
	
	return 0;
}

int main(int argc,char* argv[])
{
	return virt_main();
}