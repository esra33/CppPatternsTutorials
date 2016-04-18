#include "CConcreteCircleMeshFactory.h"

CConcreteCircleMeshFactory::CConcreteCircleMeshFactory()
{

}
CConcreteCircleMeshFactory::~CConcreteCircleMeshFactory()
{

}
IMesh* CConcreteCircleMeshFactory::CreateMeshInstance()
{
	return new CCircleMesh();
}