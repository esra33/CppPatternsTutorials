#include "ArrayCharacterDecoderBuilder.h"

void ArrayCharacterDecoderBuilder::ProcessComponent(char* c)
{
	(*c) = (*c) >= (25)? 90 : (*c) + 65;
}