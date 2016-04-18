#ifdef _WIN32
#pragma once
#endif

#ifndef CCircleMesh_h
#define CCircleMesh_h

#include "IMesh.h"

class CCircleMesh : public IMesh
{
public:
	CCircleMesh();
	~CCircleMesh();

	void Draw();
	void Setup(char* fileName);
};

#endif 