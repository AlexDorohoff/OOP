
#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "CreateShape.h"
#include "IShape.h"

using namespace std;

void Info(const std::vector<std::shared_ptr<CShape>>& shapes)
{
	for (auto shape : shapes)
	{
		cout << shape->ToString() << "\n";
	}
}

int main()
{

	std::vector<std::shared_ptr<CShape>> shapes;
	CreateShape createShape(std::cin);

	while (auto shape = createShape.ExecuteCommand())
	{
		shapes.push_back(shape);
	}

	if (!shapes.empty())
	{
		Info(shapes);
		/*
		std::cout << "Shape with max area: " << std::endl;
		std::cout << ShapeMaxArea(shapes) << std::endl;

		std::cout << "Shape with min perimeter: " << std::endl;
		std::cout << ShapeMinPerimeter(shapes) << std::endl;
	*/
	}

	return 0;
}
