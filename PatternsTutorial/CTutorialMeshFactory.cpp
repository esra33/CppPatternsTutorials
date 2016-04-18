#include "CTutorialMeshFactory.h"
#include "CConcreteCircleMeshFactory.h"

CTutorialMeshFactory::CTutorialMeshFactory()
{
	AddAbstractFactory("circleMesh", new CConcreteCircleMeshFactory());
}
CTutorialMeshFactory::~CTutorialMeshFactory()
{

}