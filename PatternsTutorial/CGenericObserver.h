#ifndef CGenericObserver_h
#define CGenericObserver_h

#ifdef _WIN32
#pragma once
#endif

#include "IObserver.h"

class CGenericObserver : public IObserver
{
	int m_Base;
	char* m_String;

public:
	CGenericObserver(int base, char* string);
	~CGenericObserver();
	bool Update(int currValue);	
};

#endif