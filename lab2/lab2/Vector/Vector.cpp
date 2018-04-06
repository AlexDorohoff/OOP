#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include <iterator>

void GetVector(std::istream& input, std::vector<double>& numbers)
{
	std::copy(std::istream_iterator<double>(input), std::istream_iterator<double>(), std::back_inserter(numbers));
}

void ProcessVector(std::vector<double>& numbers)
{
	const double min = *std::min_element(numbers.begin(), numbers.end());
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double number) { return number = number * min; });
}

void PrintVector(std::vector<double>& numbers)
{
	std::cout << "printVector";
	copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, " "));
}
