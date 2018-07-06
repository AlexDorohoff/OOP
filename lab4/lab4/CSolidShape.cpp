#pragma once
#include "stdafx.h"
#include "CSolidShape.h"
#include "CShape.h"

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::SetFillColor(std::string const& color)
{
	m_fillColor = color;
}
