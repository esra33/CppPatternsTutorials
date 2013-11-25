#ifndef CAdvancedPrototype_h
#define CAdvancedPrototype_h

#ifdef _WIN32
#pragma once
#endif

#include "CPrototype.h"

class CAdvancedPrototype : public CPrototype
{
protected:

	bool m_bForSale;

	int getSize();
	CPrototype* MethodFactory();
	CAdvancedPrototype() {}

public:
	CAdvancedPrototype(int value, char* name, int rgbaColor, bool forSale) : m_bForSale(forSale), CPrototype(value, name, rgbaColor) {}

	CPrototype* Clone();
	void PrintPrototype();
};

#endif