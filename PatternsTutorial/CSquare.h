#ifndef CSquare_h
#define CSquare_h

#ifdef _WIN32
#pragma once
#endif

#include "IShape.h"

class CSquare : public IShape 
{
	friend class CBasicFactory;
	CSquare();

public:

	void Draw();
	static int GetID();
};

#endif