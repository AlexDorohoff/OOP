#pragma once
#include "IShape.h"
#include "ISolidShape.h"

class CCircle final : public ISolidShape
{
public:
	CCircle(CPoint const& center, int& radius, std::string const& outlineColor, std::string const& fillColor);
	std::string GetFillColor() const override;
	double GetArea() const;
	double GetPerimeter() const;
	std::string ToString() const;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	int m_radius;
	std::string m_outlineColor;
	std::string m_fillColor;
};
