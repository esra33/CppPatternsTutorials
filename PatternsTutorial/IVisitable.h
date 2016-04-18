#ifdef _WIN32
#pragma once
#endif

#ifndef	IVisitable_h
#define IVisitable_h

#include "IVisitor.h"

class IVisitable
{
public:
	virtual void Accept(IVisitor* visitor)=0;
};

#endif