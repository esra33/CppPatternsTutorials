#ifndef ICommand_h
#define ICommand_h

#ifdef _WIN32
#pragma once
#endif

#include "CReceiver.h"

typedef void (CReceiver::*methodCall)(void);

class ICommand 
{
protected:
	CReceiver* m_pReciever;
	methodCall m_Call;
	
public:
	ICommand(CReceiver* reciever, methodCall particularCommand);
	~ICommand();
	virtual void Execute();
};

#endif