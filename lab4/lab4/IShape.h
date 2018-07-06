
#pragma once
#include "stdafx.h"

class CPoint
{
public:
	double x;
	double y;
};

class IShape
{
public:
	virtual ~IShape(){};
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
	virtual std::string GetOutlineColor() const = 0;
	virtual std::string ToString() const = 0;

private:
};
