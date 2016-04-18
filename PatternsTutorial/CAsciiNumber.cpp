#include "CAsciiNumber.h"

CAsciiNumber::CAsciiNumber()
{

}
CAsciiNumber::~CAsciiNumber()
{

}
int CAsciiNumber::ReadAsciiNumber(int asciiValue)
{
	int i = asciiValue - 48;

	//Bounds
	if(i > 9 || i < 0)
		return -1;

	return i;
}