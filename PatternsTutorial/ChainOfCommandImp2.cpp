#include "ChainOfCommandImp2.h"
#include <cstring>
#include <cstdio>

ChainOfCommandImp2::ChainOfCommandImp2() : ChainOfCommand() 
{

}

ChainOfCommandImp2::ChainOfCommandImp2 (ChainOfCommand* pNextCommand) : ChainOfCommand(pNextCommand)
{

}

bool ChainOfCommandImp2::InterpretCommand(char** string) 
{
	if(strlen((*string)) < 6)
	{
		printf("String is to short for cmd 1\n");
		return false;
	}
	
	printf("Your first part of the input was: %.*s\n", 6, (*string));
	(*string) += 6;
	return strlen((*string)) <= 6;
}