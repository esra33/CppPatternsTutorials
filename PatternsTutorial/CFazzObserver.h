#ifndef CFazzObserver_h
#define CFazzObserver_h

#ifdef _WIN32
#pragma once
#endif

#include "IObserver.h"

class CFazzObserver : public IObserver
{
public:
	CFazzObserver();
	~CFazzObserver();
	bool Update(int currValue);	
};

#endif