#pragma once
#include "STDAFX.H"
#include "CRectangle.h"
#include "IShape.h"
#include "ISolidShape.h"
#include <iomanip>
#include <sstream>

class CRectangle final : public ISolidShape
{

public:
	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const std::string outlineColor, std::string fillColor);
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
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
	double m_width;
	double m_height;
	std::string m_outlineColor;
	std::string m_fillColor;
};
