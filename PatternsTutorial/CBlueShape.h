#ifdef _WIN32
#pragma once
#endif

#ifndef	CBlueShape_h
#define CBlueShape_h

#include "IShapedColor.h"

/*
*	Abstraction Implementation / Bridge
*/
class CBlueShape : public IShapedColor
{
public:
	CBlueShape(int shapeId);
	CBlueShape(IShape* shape);
	~CBlueShape();
	void Print();
};

#endif