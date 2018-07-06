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

private:
	void AppendProperties(std::ostream& strm) const override;
	CPoint m_center;
	double m_radius;
	std::string m_outlineColor;
	std::string m_fillColor;
};
