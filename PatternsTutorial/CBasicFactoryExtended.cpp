#include "CBasicFactoryExtended.h"
#include "CHexagon.h"
#include "COctagon.h"

CBasicFactoryExtended::CBasicFactoryExtended() { }

IShape* CBasicFactoryExtended::CreateShape(int id) 
{
	if( id == CHexagon::GetID()) 
	{
		return new CHexagon();
	}
	if( id == COctagon::GetID())
	{
		return new COctagon();
	}

	return NULL;
}

std::list<IShape*> CBasicFactoryExtended::CreateShapeList(int id)
{
	std::list<IShape*> shapes;
	IShape* currentShape;
	int currIdVal = 1;
	while(id > 0)
	{
		if(currIdVal&id == currIdVal)
		{
			currentShape = CreateShape(currIdVal);
			if(currentShape)
			{
				shapes.push_back(currentShape);
				id -= currIdVal;
			}
		}
	}

	return shapes;
}