#ifdef _WIN32
#pragma once
#endif

#ifndef CConcreteCircleMeshFactory_h
#define CConcreteCircleMeshFactory_h

#include "IAbstractMeshFactory.h"
#include "CCircleMesh.h"

class CConcreteCircleMeshFactory : public IAbstractMeshFactory
{
public:
	CConcreteCircleMeshFactory();
	~CConcreteCircleMeshFactory();

	IMesh* CreateMeshInstance();
};

#endif 