
#pragma once
#include "isolidshape.h"

class CSolidShape : public ISolidShape
{
public:
	std::string GetFillColor() const;
	void SetFillColor(std::string const& color);
	void AppendProperties(std::ostream& strm) const override;

private:
	std::string m_fillColor;
};
