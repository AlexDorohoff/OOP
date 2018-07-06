#include "stdafx.h"
#include "CCircle.h"
constexpr double PI = 3.141592653589793238463;
using namespace std;

CCircle::CCircle(CPoint const& center, double radius)
	: m_center(center)
	, m_radius(radius)
{
}

CCircle::CCircle(CPoint const& center, double& radius, std::string const& outlineColor, std::string const& fillColor)
	: m_center(center)
	, m_radius(radius)
{
	SetOutlineColor(outlineColor);
	SetFillColor(fillColor);
}
double CCircle::GetArea() const
{
	return PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * PI * m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::AppendProperties(std::ostream& strm) const
{
	strm << "Shape: Circle"
		 << "\nRadius: " << std::to_string(GetRadius())
		 << "\nCenter: "
		 << "x :" << std::to_string(GetCenter().x) << "y : " << std::to_string(GetCenter().y);
}
