#ifdef _WIN32
#pragma once
#endif

#ifndef	IVisitor_h
#define IVisitor_h

extern class CBook;
extern class CPage;
extern class CParagraph;

class IVisitor
{
public:
	virtual void Visit(CBook* book)=0;
	virtual void Visit(CPage* page)=0;
	virtual void Visit(CParagraph* paragraph)=0;
};

#endif