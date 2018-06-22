#include "stdafx.h"
#include "CShape.h"

std::string CShape::SetOutlineColor(std::string const& outlineColor)
{
	return m_outlineColor = outlineColor;
};

std::string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CShape::ToString() const
{
	std::ostringstream strm;
	AppendProperties(strm);
	strm << "\nArea: " << GetArea() << std::endl
		 << "Perimetr: " << GetPerimeter() << std::endl
		 << "Outline color: " << GetOutlineColor() << std::endl;

	return strm.str();
}
