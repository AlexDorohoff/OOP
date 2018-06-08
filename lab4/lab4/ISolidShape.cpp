
#include "stdafx.h"
#include "ISolidShape.h"

std::string ISolidShape::GetFillColor() const
{
	return m_fillColor;
};

void ISolidShape::SetFillColor(const std::string& color)
{
	m_fillColor = color;
};
