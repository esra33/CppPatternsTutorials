#include "CConcreteMeshFactory.h"

CConcreteMeshFactory::CConcreteMeshFactory()
{

}
CConcreteMeshFactory::~CConcreteMeshFactory()
{

}
IMesh* CConcreteMeshFactory::CreateMeshInstance()
{
	return new CMesh();
}