#pragma once
#include "IShape.h"

class ISolidShape : public CShape
{
public:
	std::string GetFillColor() const;
	void SetFillColor(const std::string& color);

private:
	std::string m_fillColor;
};
