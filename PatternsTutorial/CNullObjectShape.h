#ifdef _WIN32
#pragma once
#endif

#ifndef	CNullObjectShape_h
#define CNullObjectShape_h

#include "IShape.h"

class CNullObjectShape : public IShape
{
public:
	CNullObjectShape();
	~CNullObjectShape();
	void Draw();
};

#endif