#ifndef	InterpreterInterface_h
#define InterpreterInterface_h

#ifdef _WIN32
#pragma once
#endif

#include "InterpreterContext.h"

class InterpreterInterface
{
public:
	virtual void Interpret(InterpreterContext* c) = 0;
};

#endif