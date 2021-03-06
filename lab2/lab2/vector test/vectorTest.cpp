#include "stdafx.h"
#include "../Vector/Vector.h"

bool IsEqually(const std::vector<double>& input, const std::vector<double>& output)
{
	return input == output;
}

TEST_CASE("multiplies each item by the minimum item")
{
	std::vector<double> numbers = { 2, 3, 4 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, { 4, 6, 8 }));
}

TEST_CASE("Empty input - empty output")
{
	std::vector<double> numbers = {};
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {}));
}
