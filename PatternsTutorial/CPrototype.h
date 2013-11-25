#ifndef CPrototype_h
#define CPrototype_h

#ifdef _WIN32
#pragma once
#endif

#include <string>
class CPrototype;

class CPrototype
{
protected:
	int m_value;
	char* m_Name;
	int m_RGBAColor;

	friend class CPrototype;

	virtual int getSize();
	virtual CPrototype* MethodFactory();
	CPrototype() {}
	void CopyName(char* name);

public:
	CPrototype(int value, char* name, int rgbaColor) : m_value(value), m_RGBAColor(rgbaColor)
	{
		CopyName(name);
	}

	~CPrototype();
	virtual CPrototype* Clone();
	virtual void PrintPrototype();
};

#endif