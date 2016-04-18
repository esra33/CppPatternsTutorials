#ifdef _WIN32
#pragma once
#endif

#ifndef CConcreteMeshFactory_h
#define CConcreteMeshFactory_h

#include "IAbstractMeshFactory.h"
#include "CMesh.h"

class CConcreteMeshFactory : public IAbstractMeshFactory
{
public:
	CConcreteMeshFactory();
	~CConcreteMeshFactory();
	
	IMesh* CreateMeshInstance();
};

#endif 