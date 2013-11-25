#ifndef CSingleton_h
#define CSingleton_h

#ifdef _WIN32
#pragma once
#endif

#include <stdio.h>

class CSingleton 
{
private:

	// instance
	char* m_pMessage;

	CSingleton();

public:

	static CSingleton* Instance();

	const char* GetMessage();
	void PutMessage(char* message);
	void PrintMessage();
};

#endif