#pragma once
#include "CSolidShape.h"

class CCircle final : public CSolidShape
{
public:
	CCircle(CPoint const& center, double radius);
	CCircle(CPoint const& center, double& radius, std::string const& outlineColor, std::string const& fillColor);
	double GetArea() const;
	double GetPerimeter() const;

	CPoint GetCenter() const;
	double GetRadius() const;

	std::string ToString() const override;
	std::string GetOutlineColor() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	CPoint m_center;
	double m_radius;
};
