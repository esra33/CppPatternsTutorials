#ifdef _WIN32
#pragma once
#endif

#ifndef	CShapeCollection_h
#define CShapeCollection_h

#include "IAbstractFactory.h"

class CShapeCollection
{
	IAbstractFactory* m_pBasicFactory;
	IAbstractFactory* m_pExtendedFactory;
	
	int m_ShapeCount;
	IShape** m_pShapes;

	IAbstractFactory* InitializeBasicFactory();
	IAbstractFactory* InitializeExtendedFactory();

public:
	CShapeCollection();
	~CShapeCollection();
	
	void ProduceShapes(int args[], int size);
	void PrintShapes();
};

#endif