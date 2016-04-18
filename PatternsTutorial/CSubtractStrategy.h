#ifndef	CSubtractStrategy_h
#define CSubtractStrategy_h

#ifdef _WIN32
#pragma once
#endif

#include "IStrategy.h"

class CSubtractStrategy : public IStrategy
{
public:
	CSubtractStrategy();
	~CSubtractStrategy();

	int DoMath(IStrategyDataHolder* dataHolder);
};

#endif