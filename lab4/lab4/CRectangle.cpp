#include "stdafx.h"
#include "CRectangle.h"
#include <iomanip>
#include <sstream>

CRectangle::CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const std::string outlineColor, std::string fillColor)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
	SetFillColor(fillColor);
	SetOutlineColor(outlineColor);
};
double CRectangle::GetWidth() const
{
	return abs(m_rightBottom.x - m_leftTop.x);
}

double CRectangle::GetHeight() const
{
	return abs(m_rightBottom.y - m_leftTop.y);
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetWidth() + GetHeight());
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

void CRectangle::AppendProperties(std::ostream& strm) const
{
	strm << "Shape: rectangle"
		 << "\nleft top: " << std::to_string(m_leftTop.x) << " " << std::to_string(m_leftTop.y)
		 << "\nright bottom: " << std::to_string(m_rightBottom.x) << " " << std::to_string(m_rightBottom.y)
		 << ("\nwidth: ") << std::to_string(GetWidth());
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}
