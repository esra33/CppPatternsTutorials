#include "CSubtractStrategy.h"

CSubtractStrategy::CSubtractStrategy()
{

}
CSubtractStrategy::~CSubtractStrategy()
{

}

int CSubtractStrategy::DoMath(IStrategyDataHolder* dataHolder)
{
	return dataHolder->GetA() - dataHolder->GetB();
}