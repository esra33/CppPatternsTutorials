#ifdef _WIN32
#pragma once
#endif

#ifndef IAbstractMeshFactory_h
#define IAbstractMeshFactory_h

#include "IMesh.h"

class IAbstractMeshFactory
{
public:
	virtual IMesh* CreateMeshInstance()=0;
};

#endif 