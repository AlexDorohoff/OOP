#pragma once
#include "IShape.h"

class CLineSegment final : public CShape
{
public:
	CLineSegment(const CPoint& startPoint, const CPoint& endPoint, std::string const& outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	std::string m_color;
};
