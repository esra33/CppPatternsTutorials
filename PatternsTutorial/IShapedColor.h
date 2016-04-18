#ifdef _WIN32
#pragma once
#endif

#ifndef	IShapedColor_h
#define IShapedColor_h

#include "IColor.h"
#include "IShape.h"

/*
*	Abstraction Implementation / Bridge
*/
class IShapedColor : public IColor
{
	IShape* m_pShape;

public:
	IShapedColor(int shapeId);
	IShapedColor(IShape* shape);
	~IShapedColor();
	virtual void Print();
};

#endif