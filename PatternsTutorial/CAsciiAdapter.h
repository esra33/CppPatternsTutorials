#ifdef _WIN32
#pragma once
#endif

#ifndef	CAsciiAdapter_h
#define CAsciiAdapter_h

#include "CAsciiString.h"
#include "CAsciiNumber.h"

/*
*	Adapter
*/
class CAsciiAdapter : public CAsciiString 
{
	CAsciiNumber* m_pAdaptee;

public:
	CAsciiAdapter();
	~CAsciiAdapter();
	const char* ReadAsciiNumber(int asciiValue);
};

#endif