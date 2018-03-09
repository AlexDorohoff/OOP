// flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <bitset>  

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: flipbyte.exe <decimal>\n";
		return 1;
	}

	std::string input = argv[1];
	int myint = stoi(input);

	if (myint > 10)
	{
		std::cout << "Non decimal\n";
		return 1;
	}

	std::bitset<8> binary(myint);
	std::cout << binary << "\n";
}

