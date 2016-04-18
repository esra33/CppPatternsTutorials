#ifdef _WIN32
#pragma once
#endif

#ifndef	IShapeDecorator_h
#define IShapeDecorator_h

#include "IShape.h"
/*
* Decorator:
* Base clase for specific decorators to inherit from
*/
class IShapeDecorator
{
	IShape* m_pDecoratedShape;

public:
	IShapeDecorator(IShape* shape);
	~IShapeDecorator();
	virtual void Draw();
};

#endif