#include "CAdvancedPrototype.h"

CPrototype* CAdvancedPrototype::MethodFactory()
{
	return (CPrototype*) new CAdvancedPrototype();
}

CPrototype* CAdvancedPrototype::Clone()
{
	return CPrototype::Clone();
}
void CAdvancedPrototype::PrintPrototype()
{
	CPrototype::PrintPrototype();
	printf("Is on sale? %s\n", m_bForSale? "true" : "false");
}

int CAdvancedPrototype::getSize() 
{
	return sizeof(CAdvancedPrototype);
}
