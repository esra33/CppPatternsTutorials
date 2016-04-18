#include <cstring>
#include "CBinaryTreeIterator.h"
#include "CBinaryTree.h"

template <class T> CBinaryTreeIterator<T>::CBinaryTreeIterator(CBinaryTree<T>* binaryTree, CBinaryTreeIterator* parent, int index) : m_index(index), m_Status(0), m_BinaryTree(binaryTree)
{
	m_NextNodes = new CBinaryTreeIterator*[3];
	memset(m_NextNodes, 0, 3*sizeof(CBinaryTreeIterator*));
	m_NextNodes[2] = parent;
}

template <class T> CBinaryTreeIterator<T>::~CBinaryTreeIterator()
{
	delete [] m_NextNodes;
}

template <class T> CBinaryTreeIterator<T>* CBinaryTreeIterator<T>::CreateBinaryTree(int idx)
{
	if(m_BinaryTree != NULL && idx < m_BinaryTree->Size())
	{
		T* wrapper;
		m_BinaryTree->GetItem(idx, &wrapper);
		if((*wrapper) != NULL)
		{
			return new CBinaryTreeIterator(m_BinaryTree, this, idx);
		}
	}

	return NULL;
}

template <class T> bool CBinaryTreeIterator<T>::HasNext()
{
	while(m_Status < 2)
	{
		if(m_NextNodes[m_Status] != NULL)
		{
			return true;
		}
		else
		{
			int idx = m_Status == 0? m_index*2 + 1 : 2*(m_index + 1);
			CBinaryTreeIterator* newNode = CreateBinaryTree(idx);
			if(newNode != NULL)
			{
				m_NextNodes[m_Status] = newNode;
			}
			else
			{
				++m_Status;
			}
		}
	}

	if(m_NextNodes[m_Status] != NULL)
		return m_NextNodes[m_Status]->HasNext();
	else
		return false;
}
template <class T> IIterator<T>* CBinaryTreeIterator<T>::Next()
{
	while(m_Status < 2)
	{
		if(m_NextNodes[m_Status] != NULL)
		{
			++m_Status;
			return m_NextNodes[m_Status - 1];
		}
		else
		{
			int idx = m_Status == 0? m_index*2 + 1 : 2*(m_index + 1);
			CBinaryTreeIterator* newNode = CreateBinaryTree(idx);
			if(newNode != NULL)
			{
				m_NextNodes[m_Status] = newNode;
				++m_Status;
				return m_NextNodes[m_Status - 1];
			}
		}

		++m_Status;
	}

	if(m_NextNodes[m_Status] != NULL)
	{
		m_Status = 0;
		return m_NextNodes[2]->Next();
	}

	return NULL;
}

template <class T> T* CBinaryTreeIterator<T>::GetCurrent()
{
	if(m_BinaryTree != NULL)
	{
		T* value;
		if(m_BinaryTree->GetItem(m_index, &value))
		{
			return value;
		}
	}
}