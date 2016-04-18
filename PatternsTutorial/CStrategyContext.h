#ifndef	CStrategyContext_h
#define CStrategyContext_h

#ifdef _WIN32
#pragma once
#endif

#include "IStrategy.h"

class CStrategyContext : public IStrategyDataHolder
{
	int m_a;
	int m_b;
	IStrategy* m_Strategy;

public:
	CStrategyContext(int a, int b, IStrategy* strategy);
	~CStrategyContext();
	
	int GetA();
	int GetB();

	void PrintResult();

	void ChangeStrategy(IStrategy* strategy);
};

#endif