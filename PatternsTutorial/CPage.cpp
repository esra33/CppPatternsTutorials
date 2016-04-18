#include "CPage.h"
#include <cstdlib>
#include <cstring>

CPage::CPage()
{
	m_paragraphCount = rand()%3;
	m_pParagraphs = new CParagraph*[m_paragraphCount];

	// This array is on the stack
	char* sentences[3] = {"FIRST", "SECOND", "THIRD"};

	for(int i = 0; i < m_paragraphCount; ++i)
	{
		m_pParagraphs[i] = new CParagraph(sentences[i]);
	}
}
CPage::~CPage()
{
	if(m_pParagraphs != NULL)
	{
		delete [] m_pParagraphs;
		m_pParagraphs = NULL;
	}

	m_paragraphCount = -1;
}
void CPage::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
	
	for(int i = 0; i < m_paragraphCount; ++i)
	{
		m_pParagraphs[i]->Accept(visitor);
	}
}