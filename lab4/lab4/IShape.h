
#pragma once

class CPoint
{
public:
	double x;
	double y;
};

class IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::string GetOutlineColor() const = 0;

	virtual ~IShape(){};

private:
};
