#pragma once
#include "CShape.h"
#include "IShape.h"

class CLineSegment final : public IShape
{
public:
	CLineSegment(const CPoint& startPoint, const CPoint& endPoint, std::string const& outlineColor);

	double GetPerimeter() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	std::string m_color;
	std::string m_outlineColor;
};
