#include "CConcreteVisitor.h"
#include <cstring>
#include <stdio.h>

CConcreteVisitor::CConcreteVisitor()
{
	m_Books = 0;
	m_Pages = 0; 
	m_HeaderParagraphs = 0;
	m_IntermediateParagraphs = 0;
	m_TailParagraphs = 0;
}
CConcreteVisitor::~CConcreteVisitor()
{

}

void CConcreteVisitor::Visit(CBook* book)
{
	m_Books++;
}

void CConcreteVisitor::Visit(CPage* page)
{
	m_Pages++;
}

void CConcreteVisitor::Visit(CParagraph* paragraph)
{
	const char* currParagraph = paragraph->GetParagraph();

	if(strcmp(currParagraph, "FIRST") == 0)
	{
		m_HeaderParagraphs++;
		return;
	}
	if(strcmp(currParagraph, "SECOND") == 0)
	{
		m_IntermediateParagraphs++;
		return;
	}
	if(strcmp(currParagraph, "THIRD") == 0)
	{
		m_TailParagraphs++;
		return;
	}
}

void CConcreteVisitor::Flush()
{
	printf("Books: %d\nPages %d\nHeaders: %d\nMiddles: %d\nTails: %d\n", m_Books, m_Pages, m_HeaderParagraphs, m_IntermediateParagraphs, m_TailParagraphs);
}
