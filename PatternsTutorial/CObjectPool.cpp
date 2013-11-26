#include "CObjectPool.h"

template <class T> CObjectPool<T>::CObjectPool(int limit) : m_ExistingObjects(0), m_limit(limit)
{

}
template <class T> CObjectPool<T>::~CObjectPool()
{
	T* outT;
	while(!m_ObjectPool.empty())
	{
		outT = m_ObjectPool.top();
		m_ObjectPool.pop();
		if(outT)
			delete outT;
	}
}

template <class T> T* CObjectPool<T>::GetInstance() 
{
	if(m_ObjectPool.empty() && (m_ExistingObjects < m_limit || m_limit < 0))
	{
		m_ExistingObjects++;
		return new T();
	}

	T* outT = m_ObjectPool.top();
	m_ObjectPool.pop();
	return outT;
}
template <class T> void CObjectPool<T>::Release(T** instance)
{
	if(instance != NULL && (*instance) != NULL)
	{
		m_ObjectPool.push((*instance));
		(*instance) = NULL; // clean the original variable memory this resource is locked
	}
}