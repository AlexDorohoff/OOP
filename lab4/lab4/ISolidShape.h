#pragma once
#include "CShape.h"

class ISolidShape : public CShape
{
public:
	virtual ~ISolidShape(){};
	virtual std::string GetFillColor() const = 0;

private:
};
