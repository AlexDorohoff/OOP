// ShapeTests.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../lab4/CLineSegment.h"
#include "../lab4/CRectangle.h"
#include "../lab4/CTriangle.h"
#include "../lab4/IShape.h"
#include "../lab4/ISolidShape.h"

TEST_CASE("segment has coordinates")
{

	CLineSegment line(CPoint{ 1, 1 }, CPoint{ 2, 3 }, "#ffffff");

	CHECK(CLineSegment::line.GetStartPoint().x == 0);
	CHECK(line.GetStartPoint().y == 1);
	CHECK(line.GetEndPoint().x == 2);
	CHECK(line.GetEndPoint().y == 3);
};
/*
TEST_CASE("segment has zero area")
{
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffffff");

	CHECK(line.GetArea() == 0);
};
*/
