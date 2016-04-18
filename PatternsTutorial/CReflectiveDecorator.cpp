#include "CReflectiveDecorator.h"

CReflectiveDecorator::CReflectiveDecorator(IShape* shape, bool reflective) : IShapeDecorator(shape)
{
	m_Reflective = reflective;
}
CReflectiveDecorator::~CReflectiveDecorator()
{
}
void CReflectiveDecorator::Draw()
{
	printf("This shape is %s reflective\n", m_Reflective? "" : "Not");
	IShapeDecorator::Draw();
}