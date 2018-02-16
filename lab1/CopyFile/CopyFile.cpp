// CopyFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void CopyFile(std::istream& input, std::ostream& output)
{
	std::string line;

	while (std::getline(input, line))
	{
		if (std::getline(input, line)) {
			output << line << "\n";
		} 
		else
		{
			std::cout << "Falled to getine";
		}

	}
}


int main(int argc, char* argv[])
{

	if (argc != 3) {
		std::cout << "Invalid argument count\n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	std::ofstream outputFile;
	outputFile.open(argv[2]);

	CopyFile(inputFile, outputFile);
	outputFile.flush();

}