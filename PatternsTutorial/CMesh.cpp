#include "CMesh.h"
#include <cstring>

CMesh::CMesh()
{
	m_fileName = NULL;
}
CMesh::~CMesh()
{
	if(m_fileName != NULL)
	{
		delete m_fileName;
		m_fileName = NULL;
	}
}
void CMesh::Setup(char* fileName)
{
	int size = strlen(fileName);
	m_fileName = new char[size + 1];
	memcpy(m_fileName, fileName, size);
	m_fileName[size] = '\0';
}

void CMesh::Draw()
{
	printf("%s\n", m_fileName);
}