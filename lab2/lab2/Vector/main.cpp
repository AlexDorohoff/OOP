// Vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Vector.h"

int main()
{

	std::vector<double> numbers;

	GetVector(std::cin, numbers);
	ProcessVector(numbers);
	SortVector(numbers);
	PrintVector(numbers);

	return 0;
}
