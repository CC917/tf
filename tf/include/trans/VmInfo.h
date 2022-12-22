#ifndef vminfo_l3
#define vminfo_l3

#include "context/action/LoginAndSaveToken.h"
#include "context/action/EnumSiteInfoAndSaveURI.h"
#include "context/action/CollectVmsInfo.h"
#include "context/action/PrintVmInfo.h"

bool ShouldPrint()
{
	return obj::getVmInst().total > 0;
}


/*
	LoginAndSaveToken t;
	t();
	
	EnumSiteInfoAndSaveURI tt;
	tt();

	CollectVmsInfo ttt;
	ttt();
	
	PrintVmInfo tttt;
	tttt();
*/

#endif