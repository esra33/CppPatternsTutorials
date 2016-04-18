#include "CParagraph.h"
#include <stdio.h>
#include <cstring>

CParagraph::CParagraph(char* paragraph)
{
	m_paragraphSize = strlen(paragraph);
	m_paragraph = new char[m_paragraphSize + 1];
	memset(m_paragraph, '\0', sizeof(char)*(m_paragraphSize + 1));
	memcpy(m_paragraph, paragraph, sizeof(char)*m_paragraphSize);
}
CParagraph::~CParagraph()
{
	if(m_paragraph != NULL)
	{
		delete [] m_paragraph;
		m_paragraph = NULL;
	}

	m_paragraphSize = -1;
}
void CParagraph::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
	printf(m_paragraph);
	printf("\n");
}

const char* CParagraph::GetParagraph()
{
	return m_paragraph;
}