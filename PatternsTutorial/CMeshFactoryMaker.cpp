#include "CMeshFactoryMaker.h"
#include "CConcreteMeshFactory.h"
#include <string>
#include <functional>

CMeshFactoryMaker::CMeshFactoryMaker()
{
	m_StandardMeshKey = HashFunction("mesh");
	AddAbstractFactory("mesh", new CConcreteMeshFactory());
}
CMeshFactoryMaker::~CMeshFactoryMaker()
{
	// Remove all factories
	for(std::map<unsigned int, IAbstractMeshFactory*>::iterator it = m_MeshFactories.begin(); it != m_MeshFactories.end(); it++)
	{
		delete (*it).second;
	}

	m_MeshFactories.clear();

	for(std::map<unsigned int, IMesh*>::iterator it = m_InstantiatedMesh.begin(); it != m_InstantiatedMesh.end(); it++)
	{
		delete (*it).second;
	}

	m_InstantiatedMesh.clear();
}

IMesh* CMeshFactoryMaker::CreateMeshInstance(char* meshName)
{
	if(meshName == NULL)
		return NULL;

	unsigned int hashValue = HashFunction(meshName);

	// Check if there is already an instance of the object
	std::map<unsigned int, IMesh*>::iterator iterator = m_InstantiatedMesh.find(hashValue);
	
	if(iterator != m_InstantiatedMesh.end())
	{
		return (*iterator).second;
	}

	std::map<unsigned int, IAbstractMeshFactory*>::iterator meshFactoryIterator = m_MeshFactories.find(hashValue);

	// Get the recular mesh factory and create a generic mesh
	if(meshFactoryIterator == m_MeshFactories.end())
	{
		meshFactoryIterator = m_MeshFactories.find(m_StandardMeshKey);
	}

	// create a new instance
	IMesh* instance = (*meshFactoryIterator).second->CreateMeshInstance();
	instance->Setup(meshName);

	// save current instance
	m_InstantiatedMesh.insert(std::pair<unsigned int, IMesh*>(hashValue, instance));

	return instance;
}
void CMeshFactoryMaker::AddAbstractFactory(char* factoryName, IAbstractMeshFactory* abstractFactory)
{
	unsigned int hashValue = HashFunction(factoryName);
	std::map<unsigned int, IAbstractMeshFactory*>::iterator meshFactoryIterator = m_MeshFactories.find(hashValue);

	if(meshFactoryIterator != m_MeshFactories.end())
		return;

	m_MeshFactories.insert(std::pair<unsigned int, IAbstractMeshFactory*>(hashValue, abstractFactory));
}

unsigned int CMeshFactoryMaker::HashFunction(char* value)
{
	std::string s(value);
	std::hash<std::string> hv;
	return hv(s);
}