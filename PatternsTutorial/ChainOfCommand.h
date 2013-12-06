#ifndef ChainOfCommand_h
#define ChainOfCommand_h

#ifdef _WIN32
#pragma once
#endif

class ChainOfCommand
{
protected:
	ChainOfCommand* m_pNextCommand;
	virtual bool InterpretCommand(char** string)=0;

public:
	ChainOfCommand();
	ChainOfCommand(ChainOfCommand* pNextCommand);
	~ChainOfCommand();

	void excecuteCommand(char** string);
};

#endif