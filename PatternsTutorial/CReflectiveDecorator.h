#ifdef _WIN32
#pragma once
#endif

#ifndef	CReflectiveDecorator_h
#define CReflectiveDecorator_h

#include "IShapeDecorator.h"

/*
* Decorator:
* Specific decorator for reflectiveness
*/
class CReflectiveDecorator : public IShapeDecorator
{
	bool m_Reflective;

public:
	CReflectiveDecorator(IShape* shape, bool reflective);
	~CReflectiveDecorator();
	void Draw();
};

#endif