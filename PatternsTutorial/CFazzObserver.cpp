#include <stdio.h>
#include "CFazzObserver.h"

CFazzObserver::CFazzObserver()
{

}
CFazzObserver::~CFazzObserver()
{

}
bool CFazzObserver::Update(int currValue)
{
	if(currValue%3 == 0)
	{
		printf("Fazz");
		return true;
	}

	return false;
}