#ifdef _WIN32
#pragma once
#endif

#ifndef	CParagraph_h
#define CParagraph_h

#include "IVisitable.h"

class CParagraph : public IVisitable
{
	int m_paragraphSize;
	char* m_paragraph;

public:
	CParagraph(char* paragraph);
	~CParagraph();
	void Accept(IVisitor* visitor);

	const char* GetParagraph();
};

#endif