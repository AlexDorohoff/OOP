#pragma once
#include "stdafx.h"
#include "CSolidShape.h"

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::SetFillColor(std::string const& color)
{
	m_fillColor = color;
}

void CSolidShape::AppendProperties(std::ostream& strm) const
{
	strm << "FillColor = " << GetFillColor() << "\n";
}
