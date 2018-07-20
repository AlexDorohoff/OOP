
#pragma once
#include "CShape.h"
#include "ISolidShape.h"
class CSolidShape : public ISolidShape
	, public virtual CShape
{
public:
	std::string GetFillColor() const final;
	void SetFillColor(std::string const& color);
	virtual void AppendProperties(std::ostream& strm) const = 0;

	std::string ToString() const override;
	std::string GetOutlineColor() const override;

private:
	std::string m_fillColor;
};
