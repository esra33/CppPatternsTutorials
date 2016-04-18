#ifndef	CMultiplyStrategy_h
#define CMultiplyStrategy_h

#ifdef _WIN32
#pragma once
#endif

#include "IStrategy.h"

class CMultiplyStrategy : public IStrategy
{
public:
	CMultiplyStrategy();
	~CMultiplyStrategy();
	int DoMath(IStrategyDataHolder* dataHolder);
};

#endif