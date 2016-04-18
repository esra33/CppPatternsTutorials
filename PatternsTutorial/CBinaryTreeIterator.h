#ifndef	CBinaryTreeIterator_h
#define CBinaryTreeIterator_h

#ifdef _WIN32
#pragma once
#endif

#include "IIterator.h"
#include "CBinaryTree.h"

template <class T> class CBinaryTreeIterator : public IIterator<T>
{
private:
	int m_index;
	int m_Status;
	CBinaryTree<T>* m_BinaryTree;
	CBinaryTreeIterator<T>** m_NextNodes;
		
	CBinaryTreeIterator() {};
	CBinaryTreeIterator<T>* CreateBinaryTree(int index);

public:
	CBinaryTreeIterator(CBinaryTree<T>* binaryTree, CBinaryTreeIterator* parent, int index);
	~CBinaryTreeIterator();

	bool HasNext();
	IIterator* Next();
	T* GetCurrent();
};
#endif