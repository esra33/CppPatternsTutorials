#include"CPrototype.h"

CPrototype* CPrototype::MethodFactory()
{
	return new CPrototype();
}
CPrototype::~CPrototype()
{
	delete [] m_Name;
}

int CPrototype::getSize()
{
	return sizeof(CPrototype);
}

void CPrototype::CopyName(char* name)
{
	int size = strlen(name);
	m_Name = new char[size+1];
	memcpy(m_Name, name, strlen(name));
	m_Name[size] = '\0'; // set an ending character jic
}

CPrototype* CPrototype::Clone()
{
	CPrototype* prototype = MethodFactory();
	memcpy(prototype, this, getSize());
	prototype->CopyName(m_Name);
	return prototype;
}
void CPrototype::PrintPrototype()
{
	printf(m_Name);
	printf("\n");
	printf("Value %i\n", m_value);
	printf("R:%i G:%i B:%i A:%i\n", (m_RGBAColor&0xFF000000) >> 24, (m_RGBAColor&0x00FF0000) >> 16, (m_RGBAColor&0x0000FF00) >> 8, m_RGBAColor&0x000000FF);
}	