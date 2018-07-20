
#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "IShape.h"
#include "ShapeCreator.h"

using namespace std;

void FillShapeVector(std::vector<std::shared_ptr<IShape>>& arr,
	std::istream& input)
{
	ShapeCreator inputData(input);
	while (auto currentShape = inputData.CreateShape())
	{
		arr.push_back(currentShape);
	}
}

std::string ShapeMaxArea(std::vector<std::shared_ptr<IShape>> const& arr)
{
	if (!arr.empty())
	{
		auto max = std::max_element(
			arr.begin(), arr.end(),
			[](std::shared_ptr<IShape> a, std::shared_ptr<IShape> b) {
				return a->GetArea() < b->GetArea();
			});

		return (*max)->ToString();
	}
	else
	{
		return "";
	}
}

std::string ShapeMinPerimeter(std::vector<std::shared_ptr<IShape>> const& arr)
{
	if (!arr.empty())
	{
		auto max = std::min_element(
			arr.begin(), arr.end(),
			[](std::shared_ptr<IShape> a, std::shared_ptr<IShape> b) {
				return a->GetPerimeter() < b->GetPerimeter();
			});

		return (*max)->ToString();
	}
	else
	{
		return "";
	}
}

void Info(const std::vector<std::shared_ptr<IShape>>& shapes)
{
	for (auto shape : shapes)
	{
		cout << shape->ToString() << "\n";
	}
}

int main()
{

	std::vector<std::shared_ptr<IShape>> shapes;
	FillShapeVector(shapes, std::cin);

	if (!shapes.empty())
	{
		Info(shapes);
		std::cout << "Shape with max area: " << std::endl;
		std::cout << ShapeMaxArea(shapes) << std::endl;

		std::cout << "Shape with min perimeter: " << std::endl;
		std::cout << ShapeMinPerimeter(shapes) << std::endl;
	}

	return 0;
}
