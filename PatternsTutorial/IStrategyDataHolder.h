#ifndef	IStrategyDataHolder_h
#define IStrategyDataHolder_h

#ifdef _WIN32
#pragma once
#endif

class IStrategyDataHolder
{
public:
	virtual int GetA()=0;
	virtual int GetB()=0;
};

#endif