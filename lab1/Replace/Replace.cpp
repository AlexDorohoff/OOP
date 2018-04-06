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
			std::cout << result;
		}
		else
		{
			break;
		}
	}
	return result;
}

bool CopyFileWithReplace(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& searchString, const std::string& replacementString)
{

	std::string line;

	if (!inputFile.is_open())
	{
		std::cout << "Failed to open "
				  << "inputFile"
				  << " for reading\n";
		return 1;
	}

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open "
				  << "outputFile"
				  << " for reading\n";
		return 1;
	}

	while (std::getline(inputFile, line))
	{
		outputFile << ReplaceString(line, searchString, replacementString) << "\n";
	}

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
	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);

	std::string searchString = argv[3];
	std::string replacementString = argv[4];

	if (!CopyFileWithReplace(inputFile, outputFile, searchString, replacementString))
	{
		return 1;
	};

	if (!outputFile.flush())
	{
		std::cout << "Eror, flush is not work";
		return 1;
	};
	return 0;
}
