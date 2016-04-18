#include "CBlueShape.h"

CBlueShape::CBlueShape(int shapeId) : IShapedColor(shapeId)
{
}
CBlueShape::CBlueShape(IShape* shape) : IShapedColor(shape)
{
}
CBlueShape::~CBlueShape()
{
	IShapedColor::~IShapedColor();
}
void CBlueShape::Print()
{
	printf("This shape is Blue and ");
	IShapedColor::Print();
}