#ifdef _WIN32
#pragma once
#endif

#ifndef	CComposite_h
#define CComposite_h

#include "IShape.h"
#include <vector>

/*
*	Composite
*	For this example the IShape is the component interface
*	The respective shapes are the leaf nodes.
*/
class CComposite : public IShape
{
	std::vector<IShape*> m_vShapes;

public:
	CComposite();
	~CComposite();

	// Inherited composite interface
	void Draw();

	// Agregation and removal
	void Add(IShape* shape);
	void Remove(IShape* shape);
	void Remove(int index);
	IShape* GetChild(int index);
};

#endif