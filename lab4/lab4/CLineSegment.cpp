#include "stdafx.h"
#include "CLineSegment.h"
#include <cmath>
#include <string>

CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint, std::string const& outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_color(outlineColor)
{
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}
CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}
CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
};

double CLineSegment::GetPerimeter() const
{
	return hypot(m_startPoint.x - m_endPoint.x, m_startPoint.y - m_endPoint.y);
}
std::string CLineSegment::ToString() const
{
	return static_cast<std::string>("Shape: line ")
		+ ("Area: ") + std::to_string(GetArea())
		+ (" Perimetr: ") + std::to_string(GetPerimeter())
		+ (" Outline color: ") + GetOutlineColor() + "\n";
}

double CLineSegment::GetArea() const
{
	return 0;
};
