#ifdef _WIN32
#pragma once
#endif

#ifndef CMemento_h
#define CMemento_h

#include "IShape.h"

class CMediator
{
	IShape* m_Item1;
	IShape* m_Item2;

public:
	CMediator(IShape* shape1, IShape* shape2);
	~CMediator();

	const IShape* GetShape1();
	const IShape* GetShape2();
};

#endif