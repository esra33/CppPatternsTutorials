#include "CShapeCollection.h"
#include "CFactoryMaker.h"
#include "CNullObjectShape.h"
#include <cstdlib>

IAbstractFactory* CShapeCollection::InitializeBasicFactory()
{
	if(m_pBasicFactory == NULL)
	{
		m_pBasicFactory = CFactoryMaker().createFactory(factoryType::basicFactory);
	}
	return m_pBasicFactory;
}
IAbstractFactory* CShapeCollection::InitializeExtendedFactory()
{
	if(m_pExtendedFactory == NULL)
	{
		m_pExtendedFactory = CFactoryMaker().createFactory(factoryType::extendedFactory);
	}
	return m_pExtendedFactory;
}

CShapeCollection::CShapeCollection()
{
	m_pBasicFactory = NULL;
	m_pExtendedFactory = NULL;
	m_pShapes = NULL;
}
CShapeCollection::~CShapeCollection()
{
	if(m_pBasicFactory != NULL)
	{
		delete m_pBasicFactory;
	}

	if(m_pExtendedFactory != NULL)
	{
		delete m_pExtendedFactory;
	}

	if(m_pShapes != NULL)
	{
		delete [] m_pShapes;
	}

	m_pBasicFactory = NULL;
	m_pExtendedFactory = NULL;
	m_pShapes = NULL;
}
	
void CShapeCollection::ProduceShapes(int args[], int size)
{
	m_ShapeCount = size;
	m_pShapes = new IShape*[m_ShapeCount];

	IAbstractFactory* currentFactory;
	IShape* currentShape;
	int delta;

	printf("\n");
	for(int i = 0; i < m_ShapeCount; ++i)
	{
		delta = args[i];
		if(args[i] > 2)
		{
			delta -= 2;
			currentFactory = InitializeExtendedFactory();
		}
		else
		{
			currentFactory = InitializeBasicFactory();
		}

		currentShape = currentFactory->CreateShape(delta);
		if(currentShape == NULL)
		{
			printf ("-Shape Is Null-");
			currentShape = new CNullObjectShape();
		}
		else
			printf ("-Shape IS %d-", args[i]);

		m_pShapes[i] = currentShape;
	}
	printf("\n");
}

void CShapeCollection::PrintShapes()
{
	for(int i = 0; i < m_ShapeCount; ++i)
	{
		m_pShapes[i]->Draw();
	}
}