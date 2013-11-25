#ifndef IAbstractFactory_h
#define IAbstractFactory_h

#ifdef _WIN32
#pragma once
#endif

#include "IShape.h"

class IAbstractFactory
{
public:
	virtual IShape* CreateShape(int id) = 0;
};

#endif 