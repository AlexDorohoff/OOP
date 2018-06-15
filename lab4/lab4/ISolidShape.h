#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	virtual std::string GetFillColor() const;
	virtual void SetFillColor(const std::string& color);

private:
	std::string m_fillColor;
};
