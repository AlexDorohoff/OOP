
#pragma once
#include "ISolidShape.h"

class CSolidShape : public ISolidShape
{
public:
	std::string GetFillColor() const override final;
	void SetFillColor(std::string const& color);

private:
	std::string m_fillColor;
};
