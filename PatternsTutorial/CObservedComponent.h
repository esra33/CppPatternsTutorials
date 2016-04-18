#ifndef CObservedComponent_h
#define CObservedComponent_h

#ifdef _WIN32
#pragma once
#endif

#include <list>
#include "IObserver.h"

class CObservedComponent
{
	int m_MaxValue;
	std::list<IObserver*> m_Observers;
	bool InformObservers(int currValue);

public:
	CObservedComponent(int max);
	~CObservedComponent();

	void Flush();

	void AddObserver(IObserver* pObserver);
	void RemoveObserver(IObserver* pObserver);
};

#endif