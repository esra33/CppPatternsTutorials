#include "IShapedColor.h"
#include "CFactoryMaker.h"

IShapedColor::IShapedColor(int shapeId)
{
	factoryType type = factoryType::basicFactory;
	if(shapeId < 1 || shapeId > 5)
		shapeId = 1;

	if(shapeId > 2)
	{
		shapeId -= 2;
		type = factoryType::extendedFactory;
	}

	CFactoryMaker maker;
	IAbstractFactory* factory = maker.createFactory(type);
	m_pShape = factory->CreateShape(shapeId);
	delete factory;
}
IShapedColor::IShapedColor(IShape* shape) : m_pShape(shape)
{

}
IShapedColor::~IShapedColor()
{
	if(m_pShape != NULL)
	{
		delete m_pShape;
		m_pShape = NULL;
	}
}

void IShapedColor::Print()
{
	if(m_pShape == NULL)
		return;

	m_pShape->Draw();
}