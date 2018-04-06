#include "stdafx.h"
#include "../Vector/Vector.h"

bool IsEqually(const std::vector<double>& input, const std::vector<double>& output)
{
	return input == output;
}

TEST_CASE("TestCase1")
{
	std::vector<double> numbers = { 1, 2, 3 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, { 10, 20, 30 }));
}

TEST_CASE("TestCase2")
{
	std::vector<double> numbers = { 1, 1, 1 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, { 1, 1, 1 }));
}

TEST_CASE("TestCase3")
{
	std::vector<double> numbers = {};
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {}));
}

TEST_CASE("TestCase4")
{
	std::vector<double> numbers = { 0 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, { 0 }));
}
