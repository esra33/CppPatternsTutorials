#ifdef _WIN32
#pragma once
#endif

#ifndef IMesh_h
#define IMesh_h

#include "IShape.h"

/*
* For this example, IShape would be considered 
* as the Flyweight and CMesh would be the concrete Flyweight
* Another option is to consider a CCircleMesh : CMesh
* in this situation the draw function would be that of CCircle
* and CMesh would be the Flyweight and the CCircleMesh would be the
* Concrete Flyweight.
*/

class IMesh : public IShape
{
public:
	virtual void Setup(char* fileName)=0;
};

#endif 