#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "InterpreterHex.h"

void InterpreterHex::Interpret(InterpreterContext* c)
{
	if(!c)
		return;

	char _repr[32];
	itoa(c->GetValue(), _repr, 16);
	c->SetInterpretedOutput(_repr);
}