#ifdef _WIN32
#pragma once
#endif

#ifndef CMesh_h
#define CMesh_h

#include "IMesh.h"

class CMesh : public IMesh
{
	char* m_fileName;

public:
	CMesh();
	~CMesh();

	void Draw();
	void Setup(char* fileName);
};

#endif 