#pragma once
#include "CSolidShape.h"
class CTriangle final : public CSolidShape
{
public:
	CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, std::string const& outlineColor, std::string const& fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	std::string ToString() const override;
	std::string GetOutlineColor() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
