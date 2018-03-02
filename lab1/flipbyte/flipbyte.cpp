// flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	std::string input = argv[1];
	int myint = stoi(input);
	std::cout << myint << '\n';

	if (myint > 10)
	{
		std::cout << "Non decimal\n";
		return 1;
	}
}

