#ifdef _WIN32
#pragma once
#endif

#ifndef	CAsciiNumber_h
#define CAsciiNumber_h

/*
*	Adaptee
*/
class CAsciiNumber 
{
public:
	CAsciiNumber();
	~CAsciiNumber();
	int ReadAsciiNumber(int asciiValue);
};

#endif