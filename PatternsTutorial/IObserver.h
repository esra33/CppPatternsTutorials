#ifndef IObserver_h
#define IObserver_h

#ifdef _WIN32
#pragma once
#endif

class IObserver
{
public:
	virtual bool Update(int currValue)=0;	
};

#endif