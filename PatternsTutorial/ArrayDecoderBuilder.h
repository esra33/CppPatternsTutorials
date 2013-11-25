#ifndef ArrayDecoderBuilder_h
#define ArrayDecoderBuilder_h

#ifdef _WIN32
#pragma once
#endif

class ArrayDecoderBuilder 
{
public:
	virtual void ProcessComponent(char* c)=0;
};

#endif