#ifndef ChainOfCommandImp1_h
#define ChainOfCommandImp1_h

#ifdef _WIN32
#pragma once
#endif

#include "ChainOfCommand.h"

class ChainOfCommandImp1 : public ChainOfCommand
{
protected:
	bool InterpretCommand(char** string);
public:
	ChainOfCommandImp1();
	ChainOfCommandImp1(ChainOfCommand* pNextCommand);
};

#endif