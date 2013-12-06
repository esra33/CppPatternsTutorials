#ifndef CInvoker_h
#define CInvoker_h

#ifdef _WIN32
#pragma once
#endif

#include "ICommand.h"
#include <vector>

class CInvoker
{
protected:
	std::vector<ICommand*> m_Commands;
	int m_Index;
	
public:
	CInvoker();
	~CInvoker();
	void AddAndExecuteCommand(ICommand* command);
};

#endif