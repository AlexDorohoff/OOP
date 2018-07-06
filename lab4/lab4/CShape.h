#pragma once
#include "IShape.h"
#include <iostream>
#include <string>

class CShape : public virtual IShape
{
public:
	std::string GetOutlineColor() const override final;
	std::string ToString() const override;
	void SetOutlineColor(std::string const& outlideColor);
	virtual void AppendProperties(std::ostream& strm) const = 0;

private:
	std::string m_color;
	std::string m_outlineColor;
};
