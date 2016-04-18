#include "CColorDecorator.h"
#include <cstring>

CColorDecorator::CColorDecorator(IShape* shape, char* color) : IShapeDecorator(shape)
{
	int size = strlen(color);
	m_Color = new char[size + 1];
	memcpy(m_Color, color, sizeof(char)*size);
	m_Color[size] = '\0';
}
CColorDecorator::~CColorDecorator()
{

}
void CColorDecorator::Draw()
{
	printf("This color is %s\n", m_Color);
	IShapeDecorator::Draw();
}