#ifndef	IShape_h
#define IShape_h

#ifdef _WIN32
#pragma once
#endif

#include <stdio.h>
#include "FriendClassHeaders.h"

class IShape
{
public:
	virtual void Draw()=0;
};

#endif