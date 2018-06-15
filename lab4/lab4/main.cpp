
#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "CreateShape.h"
#include "IShape.h"

using namespace std;

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
	ShapeCreator createdShape(std::cin);

	while (auto shape = createdShape.ExecuteCommand())
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
