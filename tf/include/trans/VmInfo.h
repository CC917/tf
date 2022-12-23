#ifndef vminfo_l3
#define vminfo_l3

#include "context/action/LoginAndSaveToken.h"
#include "context/action/EnumSiteInfoAndSaveURI.h"
#include "context/action/CollectVmsInfo.h"
#include "context/action/PrintVmInfo.h"

struct dummy{};

struct ShouldPrint
{
	bool operator() ()const 
	{
		return obj::getVmInst()->total > 0;
	}
};

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

typedef int Status;

/*
 * 
*/

struct SchedAction
{
	virtual Status exec() = 0;
};

template<typename PRED,typename T_ACTION>
struct OPTIONAL__ : SchedAction
{
	Status exec()
	{
		if (pred()) {
			act();
		}
	}
	
	void operator() ()
	{
		this->exec();
	}
	
	PRED pred;
	T_ACTION act;
};

template<typename T_ACTION>
struct LinkedSchedAction : SchedAction
{
	Status exec() override
	{
		t();
		return true;
	}
	T_ACTION t;
};

struct SchedSequentialAction : SchedAction
{
	Status exec()
	{
		while(current < _actions.size()) {
			_actions[current]->exec();
			current++;
		}
		return true;
	}
	
	void pushBack(SchedAction* sa)
	{
		_actions.push_back(sa);
	}
	
	std::vector<SchedAction*> _actions;
	int current = 0;
};

template<typename... T_ACTIONS> struct GenericSequential;

template<typename T_HEAD,typename... T_TAIL>
struct GenericSequential<T_HEAD,T_TAIL...> : GenericSequential<T_TAIL...>
{
	void init()
	{
		GenericSequential<T_TAIL...>::pushBack(&action);
		GenericSequential<T_TAIL...>::init();
	}
	LinkedSchedAction<T_HEAD> action;
};

#define __sync(...) __VA_ARGS__

template<>
struct GenericSequential<> : SchedSequentialAction
{
	void init() {}
};

template<typename... T_ACTIONS>
struct SEQUENTIAL__ : GenericSequential<T_ACTIONS...>
{
	SEQUENTIAL__()
	{
		GenericSequential<T_ACTIONS...>::init();
	}
};

#define __sequential(...)  SEQUENTIAL__<__VA_ARGS__>

#define __def(name,...) __VA_ARGS__ struct name

#define __as(...) : __VA_ARGS__ {}

#define __optional(...) OPTIONAL__< __VA_ARGS__ >

__def(VmInfo)__as(
	__sequential(
		__sync(LoginAndSaveToken),
		__sync(EnumSiteInfoAndSaveURI),
		__sync(CollectVmsInfo),
		__optional(ShouldPrint,__sync(PrintVmInfo))
	)
);

#endif