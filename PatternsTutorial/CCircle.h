#ifndef CCircle_h
#define CCircle_h

#ifdef _WIN32
#pragma once
#endif

#include "IShape.h"

class CCircle : public IShape 
{
	friend class CBasicFactory;
	CCircle();

public:
	
	void Draw();
	static int GetID();
};

#endif