#include"ICommand.h"

ICommand::ICommand(CReceiver* reciever, methodCall particularCommand) : m_pReciever(reciever), m_Call(particularCommand)
{

}
ICommand::~ICommand()
{

}
void ICommand::Execute()
{
	if(m_pReciever && m_Call)
		(m_pReciever->*m_Call)();
}