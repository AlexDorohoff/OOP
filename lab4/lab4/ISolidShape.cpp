
#include "stdafx.h"
#include "ISolidShape.h"

std::string ISolidShape::GetFillColor() const
{
	return m_fillColor;
};

std::string ISolidShape::SetFillColor(std::string& color)
{
	m_fillColor = color;
};
