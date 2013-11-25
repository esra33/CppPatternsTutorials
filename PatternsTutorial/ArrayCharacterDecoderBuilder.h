#ifndef ArrayCharacterDecoderBuilder_h
#define ArrayCharacterDecoderBuilder_h

#ifdef _WIN32
#pragma once
#endif

#include "ArrayDecoderBuilder.h"

class ArrayCharacterDecoderBuilder : public ArrayDecoderBuilder 
{
public:
	void ProcessComponent(char* c);
};

#endif