#pragma once
#include "stdafx.h"
#include "CSolidShape.h"

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::AppendProperties(std::ostream& strm) const
{
	strm << "FillColor = " << GetFillColor() << "\n";
}
