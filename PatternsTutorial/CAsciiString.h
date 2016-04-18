#ifdef _WIN32
#pragma once
#endif

#ifndef	CAsciiString_h
#define CAsciiString_h

/*
*	Target
*/
class CAsciiString 
{
public:
	virtual const char* ReadAsciiNumber(int asciiValue)=0;
};

#endif