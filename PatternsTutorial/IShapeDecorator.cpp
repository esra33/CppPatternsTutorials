#include "IShapeDecorator.h"

IShapeDecorator::IShapeDecorator(IShape* shape) : m_pDecoratedShape(shape)
{

}
IShapeDecorator::~IShapeDecorator()
{
	delete m_pDecoratedShape;
}
void IShapeDecorator::Draw()
{
	if(m_pDecoratedShape == NULL)
		return;

	m_pDecoratedShape->Draw();
}