#ifndef	InterpreterHex_h
#define InterpreterHex_h

#ifdef _WIN32
#pragma once
#endif

#include "InterpreterInterface.h"

class InterpreterHex : public InterpreterInterface
{
public:
	void Interpret(InterpreterContext* c);
};

#endif