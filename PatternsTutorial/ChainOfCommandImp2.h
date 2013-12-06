#ifndef ChainOfCommandImp2_h
#define ChainOfCommandImp2_h

#ifdef _WIN32
#pragma once
#endif

#include "ChainOfCommand.h"

class ChainOfCommandImp2 : public ChainOfCommand
{
protected:
	bool InterpretCommand(char** string);

public:
	ChainOfCommandImp2();
	ChainOfCommandImp2 (ChainOfCommand* pNextCommand);
};

#endif