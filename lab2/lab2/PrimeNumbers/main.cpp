
#include "stdafx.h"
#include "PrimeNumbers.h"
#include <string>
using namespace std;

bool CheckArgumentCount(int argc)
{
	if (argc != 2)
	{
		return false;
	}
	return true;
}

void PrintSet(std::set<int> PrinmeNumbersSet)
{
	for (auto item : PrinmeNumbersSet)
	{
		cout << item << endl;
	}
};
int main(int argc, char* argv[])
{
	if (!CheckArgumentCount(argc))
	{
		cout << "Wrong arguments count! Example: PrimeNumbers.exe 100 \n";
		return 1;
	}
	int upperBound;
	try
	{
		upperBound = stoi(argv[1]);
	}
	catch (exception& e)
	{
		cout << e.what() << "\n";
		return 1;
	}

	set<int> PrimeNumbersSet = GeneratePrimeNumbersSet(upperBound);

	PrintSet(PrimeNumbersSet);
}
