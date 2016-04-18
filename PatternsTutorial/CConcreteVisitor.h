#ifdef _WIN32
#pragma once
#endif

#ifndef	CConcreteVisitor_h
#define CConcreteVisitor_h

#include "IVisitor.h"
#include "CBook.h"

class CConcreteVisitor : public IVisitor
{
	int m_Books;
	int m_Pages;
	int m_HeaderParagraphs;
	int m_IntermediateParagraphs;
	int m_TailParagraphs;

public:
	CConcreteVisitor();
	~CConcreteVisitor();

	void Visit(CBook* book);
	void Visit(CPage* page);
	void Visit(CParagraph* paragraph);

	void Flush();
};

#endif