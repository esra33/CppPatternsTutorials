#include <cstring>
#include "CObservedComponent.h"

bool CObservedComponent::InformObservers(int currValue)
{
	bool response = false;
	for(std::list<IObserver*>::iterator i = m_Observers.begin(), e = m_Observers.end(); i != e; ++i)
	{
		// check if any of the observers can respond
		response = (*i)->Update(currValue) || response;
	}

	return response;
}
CObservedComponent::CObservedComponent(int max) : m_MaxValue(max)
{

}

CObservedComponent::~CObservedComponent()
{
	m_Observers.clear();
}

void CObservedComponent::Flush()
{
	printf("0\n");
	for(int i = 1; i < m_MaxValue; ++i)
	{
		if(!InformObservers(i))
		{
			printf("%i", i);
		}
		printf("\n");
	}
}

void CObservedComponent::AddObserver(IObserver* pObserver)
{
	// check that the observer doesn't exist
	for(std::list<IObserver*>::iterator i = m_Observers.begin(), e = m_Observers.end(); i != e; ++i)
	{
		if((*i) == pObserver)
			return;
	}

	m_Observers.push_back(pObserver);
}

void CObservedComponent::RemoveObserver(IObserver* pObserver)
{
	m_Observers.remove(pObserver);
}