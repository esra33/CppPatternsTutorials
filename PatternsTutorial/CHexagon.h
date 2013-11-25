#ifndef CHexagon_h
#define CHexagon_h

#ifdef _WIN32
#pragma once
#endif

#include "IShape.h"

class CHexagon : public IShape 
{
	friend class CBasicFactoryExtended;
	CHexagon();

public:
	
	void Draw();
	static int GetID();
};

#endif