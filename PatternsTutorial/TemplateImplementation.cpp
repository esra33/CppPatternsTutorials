#include "TemplateImplementation.h"
#include <stdio.h>

TemplateImplementation::TemplateImplementation()
{

}
TemplateImplementation::~TemplateImplementation()
{

}

void TemplateImplementation::OnPreExecution()
{
	printf("THIS IS A HEADER\n");
}
void TemplateImplementation::OnExecution()
{
	printf("\nWe are most likely doing something in this point\nnow that things have been processed in the step before");
}
void TemplateImplementation::OnPostExecution()
{
	printf("\nThis is the End!\n\nEL FIN!\n");
}
