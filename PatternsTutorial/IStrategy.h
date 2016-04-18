#ifndef	IStrategy_h
#define IStrategy_h

#ifdef _WIN32
#pragma once
#endif

#include "IStrategyDataHolder.h"

class IStrategy
{
public:
	virtual int DoMath(IStrategyDataHolder* dataHolder)=0;
};

#endif