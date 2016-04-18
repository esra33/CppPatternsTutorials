#include "CMultiplyStrategy.h"

CMultiplyStrategy::CMultiplyStrategy() {}
CMultiplyStrategy::~CMultiplyStrategy() {}

int CMultiplyStrategy::DoMath(IStrategyDataHolder* dataHolder)
{
	return dataHolder->GetA() * dataHolder->GetB();
}