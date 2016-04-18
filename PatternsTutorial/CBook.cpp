#include "CBook.h"
#include <stdio.h>

CBook::CBook(int pages) : m_pageCount(pages)
{
	m_pPages = new CPage[m_pageCount];	

	/*for(CPage* i = m_pPages, *max = m_pPages + m_pageCount; i < max; ++i)
	{
		i = new CPage();		
	}*/
}
CBook::~CBook()
{
	if(m_pPages != NULL)
	{
		delete [] m_pPages;
		m_pPages = NULL;
	}

	m_pageCount = -1;
}
void CBook::Accept(IVisitor* visitor)
{
	visitor->Visit(this);

	for(CPage* i = m_pPages, *max = m_pPages + m_pageCount; i < max; ++i)
	{
		i->Accept(visitor);
	}
}