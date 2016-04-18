#ifndef CFizzObserver_h
#define CFizzObserver_h

#ifdef _WIN32
#pragma once
#endif

#include "IObserver.h"

class CFizzObserver : public IObserver
{
public:
	CFizzObserver();
	~CFizzObserver();
	bool Update(int currValue);	
};

#endif