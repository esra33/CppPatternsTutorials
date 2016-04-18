#ifdef _WIN32
#pragma once
#endif

#ifndef	CColorDecorator_h
#define CColorDecorator_h

#include "IShapeDecorator.h"

/*
* Decorator:
* Specific decorator for color
*/
class CColorDecorator : public IShapeDecorator
{
	char *m_Color;	
public:
	CColorDecorator(IShape* shape, char* color);
	~CColorDecorator();
	void Draw();
};

#endif