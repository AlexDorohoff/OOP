// CopyFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool CopyStream(std::ifstream& inputFile, std::ofstream& outputFile)
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

	if (!outputFile.flush())
	{
		std::cout << "Falled to flush output file";
		return false;
	}

	return true;
}

bool CopyFile(const std::string& inputFileName, const std::string& outputFileName)
{
	std::ifstream inputFile;
	inputFile.open(inputFileName);

	std::ofstream outputFile;
	outputFile.open(outputFileName);

	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << outputFileName << " for writing\n";
		return false;
	}

	return CopyStream(inputFile, outputFile);
}

int main(int argc, char* argv[])
{

	if (argc != 3)
	{
		std::cout << "Invalid argument count\n";
		return 1;
	}

	if (!CopyFile(argv[1], argv[2]))
	{
		return 1;
	}
	return 0;
}
