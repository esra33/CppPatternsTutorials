#ifndef	CBinaryTree_h
#define CBinaryTree_h

#ifdef _WIN32
#pragma once
#endif

#include "IIterator.h"

template <class T> class CBinaryTree
{
	int m_size;
	char* m_BinaryTree;
	IIterator<T>* m_Head;

	void Add(int idx, T v);

public:
	CBinaryTree();
	~CBinaryTree();

	// Parse a char array
	void ParseCharArray(T* inputArray);

	// Print organized array
	void PrintTree();

	// Get the head of the tree
	IIterator<T*>* GetHead();

	// get an item in a position
	bool GetItem(int idx, T** wrapper);

	// get size
	int Size();
};

#endif