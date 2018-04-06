// CopyFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool CopyFile(std::istream& inputFile, std::ostream& outputFile)
{

	std::string line;

	while (std::getline(inputFile, line))
	{
		if (!(outputFile << line << "\n"))
		{
			std::cout << "Falled to getine\n";
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	std::ofstream outputFile;
	outputFile.open(argv[2]);

	if (argc != 3)
	{
		std::cout << "Invalid argument count\n";
		return 1;
	}

	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	if (!CopyFile(inputFile, outputFile))
	{
		return 1;
	}

	if (!outputFile.flush())
	{
		std::cout << "Falled to flush output file";
		return 1;
	}

	return 0;
}
