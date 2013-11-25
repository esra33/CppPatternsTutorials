#ifndef CFactoryMaker_h
#define CFactoryMaker_h

#ifdef _WIN32
#pragma once
#endif

#include "IAbstractFactory.h"

enum factoryType
{
	basicFactory,
	extendedFactory
};

static class CFactoryMaker
{
public:
	static IAbstractFactory* createFactory(factoryType factoryToUse);
};

#endif 