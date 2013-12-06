#include"ChainOfCommand.h"
#define NULL 0

ChainOfCommand::ChainOfCommand() : m_pNextCommand(NULL)
{

}
ChainOfCommand::ChainOfCommand(ChainOfCommand* pNextCommand) : m_pNextCommand(pNextCommand)
{
}
ChainOfCommand::~ChainOfCommand() 
{
}

void ChainOfCommand::excecuteCommand(char** string)
{
	if(!InterpretCommand(string) && m_pNextCommand)
	{
		m_pNextCommand->excecuteCommand(string);
	}
}