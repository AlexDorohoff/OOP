#pragma once
#include "IShape.h"

class ISolidShape : public CShape
{
public:
	std::string GetFillColor() const;
	std::string SetFillColor(std::string& color);

private:
	std::string m_fillColor;
};
