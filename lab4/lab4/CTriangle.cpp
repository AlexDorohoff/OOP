#include "stdafx.h"
#include "CTriangle.h"
#include <iomanip>
#include <math.h>
#include <sstream>

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, std::string const& outlineColor, std::string const& fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_fillColor(fillColor)
	, m_outlineColor(outlineColor)
{
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
};
CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
};
CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
};

double CTriangle::GetPerimeter() const
{
	double side1 = hypot(m_vertex1.x - m_vertex2.x, m_vertex1.y - m_vertex2.y);
	double side2 = hypot(m_vertex1.x - m_vertex3.x, m_vertex1.y - m_vertex3.y);
	double side3 = hypot(m_vertex3.x - m_vertex2.x, m_vertex3.y - m_vertex2.y);

	return side1 + side2 + side3;
}

double CTriangle::GetArea() const
{
	//	S = 0, 5 * [(x1 - x3)(y2 - y3) - (x2 - x3)(y1 - y3)].
	return abs((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y) - (m_vertex2.x - m_vertex3.x) * (m_vertex1.y - m_vertex3.y));
}

std::string CTriangle::ToString() const

{
	return static_cast<std::string>("Shape: triangle ") + static_cast<std::string>("\nVertex1: ") + std::to_string(m_vertex1.x) + " " + std::to_string(m_vertex1.y) + " " + static_cast<std::string>("\nVertex2: ") + std::to_string(m_vertex2.x) + " " + std::to_string(m_vertex2.y) + " " + static_cast<std::string>("\nVertex3: ") + std::to_string(m_vertex3.x) + " " + std::to_string(m_vertex3.y)
		+ static_cast<std::string>("\nArea: ") + std::to_string(CTriangle::GetArea()) + static_cast<std::string>("\nPerimetr: ") + std::to_string(CTriangle::GetPerimeter()) + static_cast<std::string>("\nOutline color: ") + GetOutlineColor() + "\n";
}

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
}

std::string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}
