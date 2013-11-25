#ifndef ArrayNumberDecoderBuilder_h
#define ArrayNumberDecoderBuilder_h

#ifdef _WIN32
#pragma once
#endif

#include "ArrayDecoderBuilder.h"

class ArrayNumberDecoderBuilder : public ArrayDecoderBuilder 
{
public:
	void ProcessComponent(char* c);
};

#endif