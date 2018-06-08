// lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "IShape.h"

std::string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

void CShape::SetOutlineColor(const std::string& color)
{
	m_outlineColor = color;
}
