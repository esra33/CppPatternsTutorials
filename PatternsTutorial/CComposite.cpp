#include "CComposite.h"

CComposite::CComposite()
{

}
CComposite::~CComposite()
{
	IShape* shape = m_vShapes[0];
	for(int i = 0; i < m_vShapes.size(); ++i)
	{
		delete m_vShapes[i];
	}

	// Clear destroys the elements that can destroy
	m_vShapes.clear();
}

// Inherited composite interface
void CComposite::Draw()
{
	printf("{\n");

	for(int i = 0; i < m_vShapes.size(); ++i)
	{
		m_vShapes[i]->Draw();
	}

	printf("}\n");
}

// Agregation and removal
void CComposite::Add(IShape* shape)
{
	m_vShapes.push_back(shape);
}
void CComposite::Remove(IShape* shape)
{
	for(std::vector<IShape*>::iterator i = m_vShapes.begin(); i != m_vShapes.end(); i++)
	{
		if(*i == shape)
		{
			m_vShapes.erase(i);
			delete shape;
			return;
		}
	}
}
void CComposite::Remove(int index)
{
	if(index < 0 || index >= m_vShapes.size())
		return;
		
	std::vector<IShape*>::iterator iterator = m_vShapes.begin() + index;
	IShape* shape = *iterator;
	delete shape;
	m_vShapes.erase(iterator);
}
IShape* CComposite::GetChild(int index)
{
	if(index < 0 || index >= m_vShapes.size())
		return NULL;
		
	return m_vShapes[index];
}