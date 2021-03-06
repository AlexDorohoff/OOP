// Replace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::string ReplaceString(const std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{

	if (searchString == "")
	{
		return subject;
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

bool CopyFileWithReplace(const std::string& inputFileName, const std::string& outputFileName, const std::string& searchString, const std::string& replacementString)
{

	std::string line;

	std::ifstream inputFile;
	inputFile.open(inputFileName);

	std::ofstream outputFile;
	outputFile.open(outputFileName);

	if (!inputFile.is_open())
	{
		std::cout << "Failed to open "
				  << "inputFile"
				  << " for reading\n";
		return false;
	}

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open "
				  << "outputFile"
				  << " for reading\n";
		return false;
	}

	while (std::getline(inputFile, line))
	{
		outputFile << ReplaceString(line, searchString, replacementString) << "\n";
	}

	if (!outputFile.flush())
	{
		std::cout << "Eror, flush is not work";
		return false;
	};

	return true;
}

int main(int argc, char* argv[])
{

	if (argc != 5)
	{
		std::cout << "Invalid argument count\n"
				  << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	if (!CopyFileWithReplace(argv[1], argv[2], argv[3], argv[4]))
	{
		return 1;
	};

	return 0;
}
