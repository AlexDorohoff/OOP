#pragma once
#include "ISolidShape.h"

class CRectangle final : public ISolidShape
{

public:
	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const std::string outlineColor, std::string fillColor);

	double GetArea() const;
	double GetPerimeter() const;
	std::string ToString() const;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};
