#ifndef CBasicFactory_h
#define CBasicFactory_h

#ifdef _WIN32
#pragma once
#endif

#include "IShape.h"
#include "IAbstractFactory.h"

class CBasicFactory : public IAbstractFactory
{
public:
	CBasicFactory();
	IShape* CreateShape(int id);
};

#endif 