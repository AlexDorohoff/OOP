#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../lab4/CLineSegment.h"

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
