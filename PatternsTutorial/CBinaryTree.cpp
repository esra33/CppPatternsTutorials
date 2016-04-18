#include <cstring>
#include <cmath>

#include "binaryTreeIterator.h"

template <class T> void CBinaryTree<T>::Add(int idx, T v)
{
	if(idx >= m_size || idx < 0)
		return;

	if(m_BinaryTree[idx] == NULL)
	{
		m_BinaryTree[idx] = v;
		return;
	}

	// Recursively add the components where they must be
	if(v <= m_BinaryTree[idx])
		Add(idx*2 + 1, v);
	else
		Add(2*(idx + 1), v);
}

template <class T> CBinaryTree<T>::CBinaryTree()
{
	m_BinaryTree = NULL;
	m_Head = NULL;
}

template <class T> CBinaryTree<T>::~CBinaryTree()
{
	if(m_BinaryTree != NULL)
	{
		delete [] m_BinaryTree;
		m_BinaryTree = NULL;
	}

	if(m_Head != NULL)
	{
		delete m_Head;
		m_Head = NULL;
	}
}

// Parse a char array
template <class T> void CBinaryTree<T>::ParseCharArray(T* inputArray)
{
	// if we have an existing BT return
	if(m_BinaryTree != NULL)
		return;

	int max = strlen(inputArray); 
	double size = 0;
	for(int i = 0; i < max; ++i)
	{
		size += pow((double)2, i);
	}

	m_size = (int) size;
	m_BinaryTree = new char[m_size];
	
	// set everything to 0
	memset(m_BinaryTree, NULL, m_size);

	for(int i = 0; i < max; ++i)
	{
		Add(0, inputArray[i]);
	}

	m_Head = (IIterator<T>*)(new CBinaryTreeIterator<T>(this, NULL, 0));
}

// Print organized array
template <class T> void CBinaryTree<T>::PrintTree()
{
	IIterator<T>* iterator = m_Head;

	// print first component
	printf("\n%c",*(iterator->GetCurrent()));

	// print all the components
	while(iterator->HasNext())
	{
		iterator = iterator->Next();
		printf("-%c",*(iterator->GetCurrent()));
	}
	printf("\n");
}

// Get the head of the tree
template <class T> IIterator<T*>* CBinaryTree<T>::GetHead()
{
	return m_Head;
}

// get an item in a position
template <class T> bool CBinaryTree<T>::GetItem(int idx, T** wrapper)
{
	if(idx < 0 || idx >= m_size)
		return false;

	*wrapper = m_BinaryTree + idx;
	return true;
}

// get size
template <class T> int CBinaryTree<T>::Size()
{
	return m_size;
}