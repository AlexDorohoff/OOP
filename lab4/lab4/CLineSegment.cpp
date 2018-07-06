#include "stdafx.h"
#include "CLineSegment.h"
#include <cmath>
#include <string>

CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint, std::string const& outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
	SetOutlineColor(outlineColor);
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

double CLineSegment::GetArea() const
{
	return 0;
};

void CLineSegment::AppendProperties(std::ostream& strm) const
{
	strm << "Shape: line";
};
