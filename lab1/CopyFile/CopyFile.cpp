// CopyFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void CopyFile(std::istream& input, std::ostream& output)
{
	std::string line;

	while (std::getline(input, line))
	{
		if (!(output << line << "\n"))
		{
			std::cout << "Falled to getine\n";
		}
	}
}

int OpenFiles(char** argv)
{
	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);

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

	CopyFile(inputFile, outputFile);
	outputFile.flush();
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count\n";
		return 1;
	}

	OpenFiles(argv);
	return 0;
}
