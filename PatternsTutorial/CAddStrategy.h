#ifndef	CAddStrategy_h
#define CAddStrategy_h

#ifdef _WIN32
#pragma once
#endif

#include "IStrategy.h"

class CAddStrategy : public IStrategy
{
public:
	CAddStrategy();
	~CAddStrategy();

	int DoMath(IStrategyDataHolder* dataHolder);
};

#endif