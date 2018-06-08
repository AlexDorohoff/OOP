#include "stdafx.h"
#include "CLineSegment.h"
#include <cmath>
#include <string>

CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint, std::string const& outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
	CShape::SetOutlineColor(outlineColor);
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}
CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
};

std::string CLineSegment::GetOutlineColor() const
{
	return m_color;
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return hypot(m_startPoint.x - m_endPoint.x, m_startPoint.y - m_endPoint.y);
}

std::string CLineSegment::ToString() const
{
	return static_cast<std::string>("Shape: line ") + static_cast<std::string>("Area: ") + std::to_string(GetArea()) + static_cast<std::string>(" Perimetr: ") + std::to_string(GetPerimeter()) + static_cast<std::string>(" Outline color: ") + GetOutlineColor() + "\n";
}
