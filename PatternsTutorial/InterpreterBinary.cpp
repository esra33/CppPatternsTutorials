#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "InterpreterBinary.h"

void InterpreterBinary::Interpret(InterpreterContext* c)
{
	if(!c)
		return;

	char _repr[32];
	itoa(c->GetValue(), _repr, 2);
	c->SetInterpretedOutput(_repr);
}