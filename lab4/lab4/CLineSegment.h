#pragma once
#include "CShape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint& startPoint, const CPoint& endPoint, std::string const& outlineColor);

	double GetPerimeter() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	CPoint m_startPoint;
	CPoint m_endPoint;
	std::string m_color;
	std::string m_outlineColor;
};
