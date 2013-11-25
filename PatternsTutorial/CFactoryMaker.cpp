#include "CFactoryMaker.h"
#include "CBasicFactory.h"
#include "CBasicFactoryExtended.h"

IAbstractFactory* CFactoryMaker::createFactory(factoryType factoryToUse) 
{
	switch(factoryToUse) 
	{
	case basicFactory:
		return new CBasicFactory();
	case extendedFactory:
		return new CBasicFactoryExtended();
	}

	return NULL;
}