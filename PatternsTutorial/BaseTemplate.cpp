#include "BaseTemplate.h"

BaseTemplate::BaseTemplate()
{

}
BaseTemplate::~BaseTemplate()
{

}

void BaseTemplate::ExecuteTemplate()
{
	OnPreExecution();
	OnExecution();
	OnPostExecution();
}