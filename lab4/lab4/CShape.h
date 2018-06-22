#pragma once
#include "IShape.h"
#include <iostream>
#include <string>

class CShape : public IShape
{
public:
	std::string GetOutlineColor() const override final;
	std::string ToString() const override;
	std::string SetOutlineColor(std::string const& outlideColor);

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density;
	std::string m_type;
	std::string m_color;
	std::string m_outlineColor;
};
