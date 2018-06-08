#include "stdafx.h"
#include "CreateShape.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "IShape.h"
#include "ISolidShape.h"
CreateShape::CreateShape(std::istream& input)
	: m_actionMap({ { "line", std::bind(&CreateShape::CreateLine, this, std::placeholders::_1) },

		  { "triangle", std::bind(&CreateShape::CreateTriangle, this, std::placeholders::_1) } })

	/*	  { "rectangle", std::bind(&CreateShape::CreateRectangle, this, std::placeholders::_1) },
		  { "circle", std::bind(&CreateShape::CreateCircle, this, std::placeholders::_1) } })
	*/
	, m_input(input){};

std::shared_ptr<CShape> CreateShape::ExecuteCommand() const
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

std::shared_ptr<CShape> CreateShape::CreateLine(std::istream& args) const
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

std::shared_ptr<CShape> CreateShape::CreateTriangle(std::istream& args) const
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
/*
std::shared_ptr<CShape> CreateShape::CreateRectangle(std::istream& args) const {

};
*/
