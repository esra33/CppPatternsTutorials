#include "CRedShape.h"

CRedShape::CRedShape(int shapeId) : IShapedColor(shapeId)
{
}
CRedShape::CRedShape(IShape* shape) : IShapedColor(shape)
{
}
CRedShape::~CRedShape()
{
	IShapedColor::~IShapedColor();
}
void CRedShape::Print()
{
	printf("This shape is Red and ");
	IShapedColor::Print();
}