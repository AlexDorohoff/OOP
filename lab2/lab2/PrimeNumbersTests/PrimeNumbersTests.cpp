// PrimeNumbersTests.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "../PrimeNumbers/PrimeNumbers.h"

bool IsEqual(const std::set<int>& x, const std::set<int>& y)
{
	return x == y;
}

TEST_CASE("test prime numbers sets")
{
	CHECK(IsEqual(GeneratePrimeNumbersSet(1), {}));
	CHECK(IsEqual(GeneratePrimeNumbersSet(0), {}));
	CHECK(IsEqual(GeneratePrimeNumbersSet(2), { 2 }));
	CHECK(IsEqual(GeneratePrimeNumbersSet(10), { 2, 3, 5, 7 }));
	CHECK(IsEqual(GeneratePrimeNumbersSet(-1), {}));
	CHECK(IsEqual(GeneratePrimeNumbersSet(-10), {}));
	/*буквы отсеиваем на этапе получения параметров*/
}
