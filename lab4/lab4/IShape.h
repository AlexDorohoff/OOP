
#pragma once
#include "stdafx.h"

class CPoint
{
public:
	double x;
	double y;
};

class CShape
{
public:
	CShape(const std::string& type, double density);
	virtual double GetArea() const;
	virtual double GetPerimeter() const;
	std::string ToString() const;
	std::string GetOutlineColor() const;
	void SetOutlineColor(const std::string& color);

private:
	std::string m_outlineColor;
};
