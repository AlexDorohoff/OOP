// ShapeTests.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../lab4/CLineSegment.h"
#include "../lab4/CRectangle.h"
#include "../lab4/CTriangle.h"
#include "../lab4/IShape.h"
#include "../lab4/ISolidShape.h"
#include <cmath>

TEST_CASE("segment has coordinates")
{

	CLineSegment line(CPoint{ 1, 1 }, CPoint{ 2, 3 }, "#ffffff");

	CHECK(line.GetStartPoint().x == 1);
	CHECK(line.GetStartPoint().y == 1);
	CHECK(line.GetEndPoint().x == 2);
	CHECK(line.GetEndPoint().y == 3);
};

TEST_CASE("segment has zero area")
{
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffffff");

	CHECK(line.GetArea() == 0);
};

TEST_CASE("segment has lenth")
{
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffffff");
	CHECK(static_cast<int>(line.GetPerimeter()) == 2);
}

TEST_CASE("segment has info")
{
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffffff");
	CHECK(line.ToString() == "Shape: line Area: 0.000000 Perimetr: 2.828427 Outline color: #ffffff\n");
}

TEST_CASE("triangle has a coordinates")
{
	CTriangle triangle({ 1, 2 }, { 3, 4 }, { 4, 1 }, "#fff", "#000");
	CHECK(triangle.GetVertex1().x == 1);
	CHECK(triangle.GetVertex1().y == 2);
	CHECK(triangle.GetVertex2().x == 3);
	CHECK(triangle.GetVertex2().y == 4);
	CHECK(triangle.GetVertex3().x == 4);
	CHECK(triangle.GetVertex3().y == 1);
}

TEST_CASE("triangle has a perimeter")
{
	CTriangle triangle({ 1, 2 }, { 3, 4 }, { 4, 2 }, "#fff", "#000");
	CHECK((std::round(triangle.GetPerimeter() * 100) / 100) == 8.06);
}

TEST_CASE("triangle has a area")
{
	CTriangle triangle({ 1, 2 }, { 3, 4 }, { 4, 2 }, "#fff", "#000");
	CHECK(triangle.GetArea() == 6.0);
}

TEST_CASE("triangle has info")
{
	CTriangle triangle({ 1, 2 }, { 3, 4 }, { 4, 2 }, "#fff", "#000");
	CHECK(triangle.ToString() == R"(Shape: triangle
Vertex1: 1.000000 2.000000
Vertex2: 3.000000 4.000000
Vertex3: 4.000000 2.000000
Area: 6.000000
Perimetr: 8.064495
Outline color: #fff
)");
}

TEST_CASE("rectangle has coordinates of the left upper point and the lower right point")
{
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(rectangle.GetLeftTop().x == 1);
	CHECK(rectangle.GetLeftTop().y == 8);
	CHECK(rectangle.GetRightBottom().x == 4);
	CHECK(rectangle.GetRightBottom().y == 5);
};

TEST_CASE("rectangle has width")
{
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");
	CHECK(static_cast<int>(rectangle.GetWidth()) == 3);
};

TEST_CASE("rectangle has height")
{
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");
	CHECK(static_cast<int>(rectangle.GetHeight()) == 3);
};

TEST_CASE("rectangle has area")
{
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");
	CHECK(static_cast<int>(rectangle.GetArea()) == 9);
};

TEST_CASE("rectangle has perimeter")
{
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");
	CHECK(static_cast<int>(rectangle.GetPerimeter()) == 12);
};
