#pragma once
#include "CSolidShape.h"
#include <iomanip>
#include <sstream>

class CRectangle final : public CSolidShape
{

public:
	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const std::string outlineColor, std::string fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	void AppendProperties(std::ostream& strm) const override;
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
	std::string m_outlineColor;
	std::string m_fillColor;
};
