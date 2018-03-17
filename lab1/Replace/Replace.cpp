// Replace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::string ReplaceString(const std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{
	if (searchString == "")
	{
		std::cout << "Search line is empty ";
		return subject;
	}

	if (replacementString == "")
	{
		std::cout << "Replace line is empty ";
	}

	size_t pos = 0;
	std::string result;
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		result.append(subject, pos, foundPos - pos);
		if (foundPos != std::string::npos)
		{
			result.append(replacementString);
			pos = foundPos + searchString.length();
		}
		else
		{
			break;
		}
	}
	return result;
}

int OpenFiles(char** argv)
{
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	std::ofstream outputFile(argv[2]);
	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	return 0;
}

bool CopyFileWithReplace(char** argv)
{
	if (!OpenFiles(argv))
	{
		return 1;
	};

	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);

	std::string searchString = argv[3];
	std::string replacementString = argv[4];
	std::string line;

	std::cout << argv[3];

	while (std::getline(inputFile, line))
	{
		outputFile << ReplaceString(line, searchString, replacementString) << "\n";
	}
	//outputFile.flush();
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid argument count\n"
				  << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	if (!CopyFileWithReplace(argv))
	{
		return 1;
	};
	return 0;
}
