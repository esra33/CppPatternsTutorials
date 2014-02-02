#ifndef	InterpreterContext_h
#define InterpreterContext_h

#ifdef _WIN32
#pragma once
#endif

#include <stdio.h>

class InterpreterContext
{
	int m_value;
	char* m_sInterpretedOutput;
	
public:
	InterpreterContext(int value);
	~InterpreterContext();

	void SetInterpretedOutput(char* output);
	void FlushInterpretedOutput();

	const int GetValue();
};

#endif