#ifndef CString_h
#define CString_h

#ifdef _WIN32
#pragma once
#endif

#include "CObjectPool.h"
#include <cstring>

class CString
{
protected:
	
	char* m_String;

	bool DoInternalCheck(char* _s);
	~CString();

	template<class T> friend class CObjectPool;

public:
	
	// param int limit: -1 for limitless, any other N for limit
	CString();

	// prints the memory location of this object and its content
	void Flush();
	
	void Set(char* _s);
};

#endif