
#pragma once
#include "CShape.h"
#include "ISolidShape.h"
class CSolidShape : public ISolidShape
	, public CShape
{
public:
	std::string GetFillColor() const final;
	void SetFillColor(std::string const& color);
	virtual void AppendProperties(std::ostream& strm) const = 0;

private:
	std::string m_fillColor;
};
