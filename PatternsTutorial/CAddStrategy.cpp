#include "CAddStrategy.h"

CAddStrategy::CAddStrategy() {}
CAddStrategy::~CAddStrategy() {}

int CAddStrategy::DoMath(IStrategyDataHolder* dataHolder)
{
	return dataHolder->GetA() + dataHolder->GetB();
}