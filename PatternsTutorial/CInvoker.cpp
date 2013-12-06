#include"CInvoker.h"

CInvoker::CInvoker() : m_Index(0)
{

}
CInvoker::~CInvoker()
{
	for(int i = 0; i < m_Commands.size(); i++)
	{
		if(m_Commands[i])
			delete m_Commands[i];
		m_Commands[i] = NULL;
	}
}
void CInvoker::AddAndExecuteCommand(ICommand* command)
{
	if(!command)
		return;

	m_Commands.push_back(command);
	command->Execute();
	printf("\n");
}