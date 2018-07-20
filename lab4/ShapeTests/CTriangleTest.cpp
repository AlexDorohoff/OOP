#include "../../Catch/catch.hpp"
#include "../lab4/CTriangle.h"

TEST_CASE("Can take a info")
{
	CTriangle triangle({ 1, 2 }, { 3, 4 }, { 4, 2 }, "#fff", "#000");
	CHECK(triangle.ToString() == R"(Shape: triangle
Fill color: #000
Vertex1: 1.000000 2.000000
Vertex2: 3.000000 4.000000
Vertex3: 4.000000 2.000000
Area: 6
Perimetr: 8.0645
Outline color: #fff
)");
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
Fill color: #000
Vertex1: 1.000000 2.000000
Vertex2: 3.000000 4.000000
Vertex3: 4.000000 2.000000
Area: 6
Perimetr: 8.0645
Outline color: #fff
)");
}
