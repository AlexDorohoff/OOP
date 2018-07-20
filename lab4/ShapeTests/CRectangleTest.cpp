#include "../../Catch/catch.hpp"
#include "../lab4/CRectangle.h"
TEST_CASE("Rectangle has its points, black outlinecolor and white fillcolor by default")
{
	CRectangle rectangle({ 0, 1 }, { 1, 0 }, { "#fffff" }, { "#00000" });
	CHECK(rectangle.GetLeftTop().x == 0);
	CHECK(rectangle.GetLeftTop().y == 1);
	CHECK(rectangle.GetRightBottom().x == 1);
	CHECK(rectangle.GetRightBottom().y == 0);
	CHECK(rectangle.GetOutlineColor() == "#fffff");
	CHECK(rectangle.GetFillColor() == "#00000");
}

TEST_CASE("Rectangle has its points, outlinecolor and fillcolor")
{
	CRectangle rectangle({ 1, 0 }, { 0, 1 }, "#FF00FF", "#00FF00");
	CHECK(rectangle.GetLeftTop().x == 1);
	CHECK(rectangle.GetLeftTop().y == 0);
	CHECK(rectangle.GetRightBottom().x == 0);
	CHECK(rectangle.GetRightBottom().y == 1);
	CHECK(rectangle.GetOutlineColor() == "#FF00FF");
	CHECK(rectangle.GetFillColor() == "#00FF00");
}

TEST_CASE("Rectangle has correct perimeter and area")
{
	CRectangle rectangle({ 1, 0 }, { 0, 1 }, { "#ffff" }, { "#0000" });
	CHECK(rectangle.GetPerimeter() == 4.0);
	CHECK(rectangle.GetArea() == 1.0);
}

TEST_CASE("Rectangle has text representation")
{
	CRectangle rectangle({ 1, 0 }, { 0, 1 }, "#090909", "#FF00FF");
	CHECK(rectangle.ToString() == R"(Shape: rectangle
Fill color: #FF00FF
left top: 1.000000 0.000000
right bottom: 0.000000 1.000000
width: 1.000000
Area: 1
Perimetr: 4
Outline color: #090909
)");
}
