#include <stdio.h>
#include "CFizzObserver.h"

CFizzObserver::CFizzObserver()
{

}
CFizzObserver::~CFizzObserver()
{

}
bool CFizzObserver::Update(int currValue)
{
	if(currValue%7 == 0)
	{
		printf("Fizz");
		return true;
	}

	return false;
}