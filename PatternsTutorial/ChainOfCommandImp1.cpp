#include "ChainOfCommandImp1.h"
#include <cstring>
#include <cstdio>

ChainOfCommandImp1::ChainOfCommandImp1() : ChainOfCommand() 
{

}

ChainOfCommandImp1::ChainOfCommandImp1 (ChainOfCommand* pNextCommand) : ChainOfCommand(pNextCommand)
{

}

bool ChainOfCommandImp1::InterpretCommand(char** string) 
{
	if(strlen((*string)) < 32)
	{
		printf("String is to short for cmd 1\n");
		return false;
	}
	
	printf("Your input was: %s\n", (*string));
	return true;
}