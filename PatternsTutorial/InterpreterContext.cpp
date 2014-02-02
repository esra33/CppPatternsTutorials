#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "InterpreterContext.h"

InterpreterContext::InterpreterContext(int value) : m_value(value) 
{
	m_sInterpretedOutput = new char[32];
	itoa(value, m_sInterpretedOutput, 10);
}

InterpreterContext::~InterpreterContext()
{
	if(m_sInterpretedOutput)
	{
		delete [] m_sInterpretedOutput;
		m_sInterpretedOutput = NULL;
	}
}

void InterpreterContext::SetInterpretedOutput(char* output)
{
	if(!output)
		return;

	if(m_sInterpretedOutput)
		delete [] m_sInterpretedOutput;

	int size = strlen(output);
	m_sInterpretedOutput = new char[size + 1];
	memcpy(m_sInterpretedOutput, output, size);
	m_sInterpretedOutput[size] = '\0';
}

void InterpreterContext::FlushInterpretedOutput()
{
	printf(m_sInterpretedOutput);
	printf("\n");
}

const int InterpreterContext::GetValue()
{
	return m_value;
}