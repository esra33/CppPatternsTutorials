#ifdef _WIN32
#pragma once
#endif

#ifndef	CRedShape_h
#define CRedShape_h

#include "IShapedColor.h"

/*
*	Abstraction Implementation / Bridge
*/
class CRedShape : public IShapedColor
{
public:
	CRedShape(int shapeId);
	CRedShape(IShape* shape);
	~CRedShape();
	void Print();
};

#endif