#ifndef CBasicFactoryExtended_h
#define CBasicFactoryExtended_h

#ifdef _WIN32
#pragma once
#endif

#include <list>
#include "IShape.h"
#include "IAbstractFactory.h"

class CBasicFactoryExtended : public IAbstractFactory
{
public:
	CBasicFactoryExtended();
	std::list<IShape*> CreateShapeList(int id);
	IShape* CreateShape(int id);
};

#endif 