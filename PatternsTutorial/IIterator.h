#ifndef	IIterator_h
#define IIterator_h

#ifdef _WIN32
#pragma once
#endif

template <class T> class IIterator
{
public:
	virtual bool HasNext() = 0;
	virtual IIterator* Next() = 0;
	virtual T* GetCurrent() = 0;
};

#endif