#ifdef _WIN32
#pragma once
#endif

#ifndef	CPage_h
#define CPage_h

#include "IVisitable.h"
#include "CParagraph.h"

class CPage : public IVisitable
{
	int m_paragraphCount;
	CParagraph** m_pParagraphs;

public:
	CPage();
	~CPage();
	void Accept(IVisitor* visitor);
};

#endif