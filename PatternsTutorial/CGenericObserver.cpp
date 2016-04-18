#include <cstring>
#include <stdio.h>
#include "CGenericObserver.h"

CGenericObserver::CGenericObserver(int base, char* string) : m_Base(base)
{
	int size = strlen(string);
	m_String = new char[size + 1];
	memcpy(m_String, string, size*sizeof(char));
	m_String[size] = '\0';
}
CGenericObserver::~CGenericObserver()
{
	if(m_String != NULL)
	{
		delete [] m_String;
		m_String = NULL;
	}
}
bool CGenericObserver::Update(int currValue)
{
	if(m_Base == 0)
		return false;

	if(currValue%m_Base == 0)
	{
		printf(m_String);
		return true;
	}

	return false;
}