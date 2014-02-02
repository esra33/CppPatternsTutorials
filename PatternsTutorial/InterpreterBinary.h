#ifndef	InterpreterBinary_h
#define InterpreterBinary_h

#ifdef _WIN32
#pragma once
#endif

#include "InterpreterInterface.h"

class InterpreterBinary : public InterpreterInterface
{
public:
	void Interpret(InterpreterContext* c);
};

#endif