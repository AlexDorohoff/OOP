// CopyFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool CopyFile(char** argv)
{
	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);
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
	};
	return true;
}

bool OpenFiles(char** argv)
{
	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);

	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return false;
	}

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << argv[2] << " for writing\n";
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count\n";
		return 1;
	}

	if (!OpenFiles(argv))
	{
		return 1;
	};

	if (!CopyFile(argv))
	{
		return 1;
	};

	return 0;
}
