#include "ArrayNumberDecoderBuilder.h"

void ArrayNumberDecoderBuilder::ProcessComponent(char* c) 
{
	(*c) = (*c) >= (9)? 57 : (*c) + 48;
}