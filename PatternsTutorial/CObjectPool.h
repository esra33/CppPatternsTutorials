#ifndef CObjectPool_h
#define CObjectPool_h

#ifdef _WIN32
#pragma once
#endif

#include <stack>

template<class T> class CObjectPool
{
protected:
	
	int m_limit;
	int m_ExistingObjects;
	std::stack<T*> m_ObjectPool;

public:
	
	// param int limit: -1 for limitless, any other N for limit
	CObjectPool(int limit);
	~CObjectPool();

	T* GetInstance();
	void Release(T** instance);
};

#endif