#pragma once
#include "ISolidShape.h"

class CTriangle final : public ISolidShape
{
public:
	CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, std::string const& outlineColor, std::string const& fillColor);

	double GetArea() const;
	double GetPerimeter() const;
	std::string ToString() const;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
