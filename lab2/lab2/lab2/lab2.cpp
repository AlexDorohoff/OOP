// lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../../../catch/catch.hpp"
unsigned int Factorial(unsigned int number)
{
	return number <= 1 ? 1 : Factorial(number - 1) * number;
}

unsigned int Fibonacci(unsigned int index)
{
	return (index <= 1) ? 1 : Fibonacci(index - 1) + Fibonacci(index - 2);
}

int CalcArithmeticSeries(int a0, int commonDifference, int size)
{
	if (size != 1)
	{
		int lastNum = (a0 + (commonDifference * (size - 1)));
		int sum = ((a0 + lastNum) / 2) * size;
		return sum;
	}
	else
	{
		return (a0);
	}
}

TEST_CASE("Check CalcArithmeticSeries", "[CalcArithmeticSeries]")
{
	REQUIRE(CalcArithmeticSeries(0, 0, 0) == 0);
	REQUIRE(CalcArithmeticSeries(1, 1, 1) == 1);
	REQUIRE(CalcArithmeticSeries(1, 2, 10) == 100);
}

TEST_CASE("Fibonacci numbers are computed", "[Fibonacci]")
{
	REQUIRE(Fibonacci(0) == 1);
	REQUIRE(Fibonacci(1) == 1);
	REQUIRE(Fibonacci(2) == 2);
	REQUIRE(Fibonacci(10) == 89);
}

TEST_CASE("Factorials are computed", "[factorial]")
{
	REQUIRE(Factorial(0) == 1);
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
};
