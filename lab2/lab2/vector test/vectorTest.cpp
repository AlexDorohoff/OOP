#include "stdafx.h"
#include "../Vector/Vector.h"

bool IsEqually(const std::vector<double>& input, const std::vector<double>& output)
{
	return input == output;
}

TEST_CASE("Multiple elements")
{
	std::vector<double> numbers = { 2, 3, 4 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, { 4, 6, 8 }));
}

TEST_CASE("Full input - full output")
{
	std::vector<double> numbers = {};
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {}));
}

TEST_CASE("Zero number input - zero number output")
{
	std::vector<double> numbers = { 0 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, { 0 }));
}

TEST_CASE("One zero number input - all zero numbers output")
{
	std::vector<double> numbers = { 0, 5, 7 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, { 0, 0, 0 }));
}
