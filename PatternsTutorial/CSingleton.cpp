#include "CSingleton.h"

CSingleton::CSingleton() : m_pMessage(NULL) {}

CSingleton* CSingleton::Instance()
{
	static CSingleton pInstance;
	return &pInstance;
}

const char* CSingleton::GetMessage()
{
	return (const char*) m_pMessage;
}

void CSingleton::PutMessage(char* message)
{
	m_pMessage = message;
}

void CSingleton::PrintMessage() 
{
	if(m_pMessage == NULL)
	{
		return;
	}

	printf(m_pMessage);
}