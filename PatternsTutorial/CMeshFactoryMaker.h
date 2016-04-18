#ifdef _WIN32
#pragma once
#endif

#ifndef CMeshFactoryMaker_h
#define CMeshFactoryMaker_h

#include "IAbstractMeshFactory.h"
#include <map>

/*
* This class will act as the main flyweight factory and object pool
* this way it should not be possible to create 
*/
class CMeshFactoryMaker
{
	std::map<unsigned int, IAbstractMeshFactory*> m_MeshFactories;
	std::map<unsigned int, IMesh*> m_InstantiatedMesh;

protected:
	unsigned int m_StandardMeshKey;

	unsigned int HashFunction(char* value);

public:
	CMeshFactoryMaker();
	~CMeshFactoryMaker();

	static CMeshFactoryMaker* Instance();

	IMesh* CreateMeshInstance(char* meshName);
	void AddAbstractFactory(char* factoryName, IAbstractMeshFactory* abstractFactory);
};

#endif 