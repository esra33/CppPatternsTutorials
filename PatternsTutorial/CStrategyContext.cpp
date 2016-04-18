#include <stdio.h>
#include "CStrategyContext.h"

CStrategyContext::CStrategyContext(int a, int b, IStrategy* strategy) : m_a(a), m_b(b), m_Strategy(strategy) {}

// The strategies are deleted by someone else
CStrategyContext::~CStrategyContext()
{

}

int CStrategyContext::GetA()
{
	return m_a;
}

int CStrategyContext::GetB()
{
	return m_b;
}

void CStrategyContext::PrintResult()
{
	int result = m_Strategy->DoMath(this);

	printf("%d\n", result);	
}

void CStrategyContext::ChangeStrategy(IStrategy* strategy)
{
	m_Strategy = strategy;
}