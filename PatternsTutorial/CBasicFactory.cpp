#include "CBasicFactory.h"
#include "CCircle.h"
#include "CSquare.h"

CBasicFactory::CBasicFactory() {}
IShape* CBasicFactory::CreateShape(int id) 
{
	if(id == CCircle::GetID()) {
		return (IShape*) new CCircle();
	}

	if(id == CSquare::GetID()) {
		return (IShape*) new CSquare();
	}

	return NULL;
}