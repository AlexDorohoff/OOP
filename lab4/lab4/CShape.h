#pragma once
#include "IShape.h"
#include <iostream>
#include <string>

class CShape : public virtual IShape
{
public:
	std::string GetOutlineColor() const final;
	std::string ToString() const override;
	void SetOutlineColor(std::string const& outlideColor);

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	std::string m_outlineColor;
};
