#ifdef _WIN32
#pragma once
#endif

#ifndef	IColor_h
#define IColor_h

/*
*	Abstraction
*/
class IColor
{
public:
	virtual void Print()=0;
};

#endif