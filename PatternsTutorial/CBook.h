#ifdef _WIN32
#pragma once
#endif

#ifndef	CBook_h
#define CBook_h

#include "IVisitable.h"
#include "CPage.h"

class CBook : public IVisitable
{
	int m_pageCount;
	CPage* m_pPages;

public:
	CBook(int pages);
	~CBook();
	void Accept(IVisitor* visitor);
};

#endif