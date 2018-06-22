#include "stdafx.h"
#include "ShapeCreator.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include "ISolidShape.h"
ShapeCreator::ShapeCreator(std::istream& input)
	: m_actionMap({ { "line", std::bind(&ShapeCreator::CreateLine, this, std::placeholders::_1) },

		  { "triangle", std::bind(&ShapeCreator::CreateTriangle, this, std::placeholders::_1) },

		  { "rectangle", std::bind(&ShapeCreator::CreateRectangle, this, std::placeholders::_1) } })
	//  { "circle", std::bind(&ShapeCreator::CreateCircle, this, std::placeholders::_1) } })

	, m_input(input){};

std::shared_ptr<IShape> ShapeCreator::CreateShape() const
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string figure;
	strm >> figure;

	auto it = m_actionMap.find(figure);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

std::shared_ptr<IShape> ShapeCreator::CreateLine(std::istream& args) const
{
	CPoint point1, point2;
	std::string outlineColor, inputValue;

	try
	{
		args >> inputValue;
		std::cout << inputValue << "\n";
		point1.x = std::stod(inputValue);
		std::cout << point1.x << "\n";
		args >> inputValue;
		std::cout << inputValue << "\n";
		point1.y = std::stod(inputValue);

		inputValue.clear();

		args >> inputValue;
		point2.x = std::stod(inputValue);
		args >> inputValue;
		point2.y = std::stod(inputValue);
		inputValue.clear();

		args >> outlineColor;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CLineSegment>(point1, point2, outlineColor);
}

std::shared_ptr<IShape> ShapeCreator::CreateTriangle(std::istream& args) const
{
	CPoint vertex1, vertex2, vertex3;
	std::string outlineColor, fillColor, inputValue;
	try
	{
		args >> inputValue;
		vertex1.x = std::stod(inputValue);
		args >> inputValue;
		vertex1.y = std::stod(inputValue);

		inputValue.clear();

		args >> inputValue;
		vertex2.x = std::stod(inputValue);
		args >> inputValue;
		vertex2.y = std::stod(inputValue);

		inputValue.clear();

		args >> inputValue;
		vertex3.x = std::stod(inputValue);
		args >> inputValue;
		vertex3.y = std::stod(inputValue);
		inputValue.clear();

		args >> outlineColor;

		args >> fillColor;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

std::shared_ptr<IShape> ShapeCreator::CreateRectangle(std::istream& args) const
{
	CPoint leftTop, rigthBottom;
	std::string outlineColor, fillColor, inputValue;
	try
	{
		args >> inputValue;
		leftTop.x = std::stod(inputValue);
		args >> inputValue;
		leftTop.y = std::stod(inputValue);

		inputValue.clear();

		args >> inputValue;
		rigthBottom.x = std::stod(inputValue);
		args >> inputValue;
		rigthBottom.y = std::stod(inputValue);

		args >> outlineColor;

		args >> fillColor;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}
	return std::make_shared<CRectangle>(leftTop, rigthBottom, outlineColor, fillColor);
}

/*
std::shared_ptr<IShape> ShapeCreator::CreateCircle(std::istream& args) const
{
	CPoint center;
	double radius;
	std::string outlineColor, fillColor, inputValue;
	try
	{

		args >> inputValue;
		center.x = std::stod(inputValue);
		args >> inputValue;
		center.y = std::stod(inputValue);

		inputValue.clear();

		args >> inputValue;
		radius = std::stoi(inputValue);
		args >> outlineColor;

		args >> fillColor;
	}
	*/
