#ifndef COctagon_h
#define COctagon_h

#ifdef _WIN32
#pragma once
#endif

#include "IShape.h"

class COctagon : public IShape 
{
	friend class CBasicFactoryExtended;
	COctagon();

public:
	
	void Draw();
	static int GetID();
};

#endif