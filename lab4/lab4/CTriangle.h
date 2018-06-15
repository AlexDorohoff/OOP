#pragma once
#include "IShape.h"
#include "ISolidShape.h"

class CTriangle final : public ISolidShape
{
public:
	CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, std::string const& outlineColor, std::string const& fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	std::string m_outlineColor;
	std::string m_fillColor;
};
