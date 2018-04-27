// Dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

string ReadDictionary(const ifstream& inputFile, const string& word)
{
	map<string, string> dictionary{
		{}
	};
}

string Translate(const string& inputWord, const string& inputFileName)
{

	ifstream inputFile;
	inputFile.open(inputFileName);

	string word, translation;

	if (!inputFile.is_open())
	{
		cout << "Failed to open "
			 << "inputFile"
			 << " for reading\n";
		return false;
	}

	while (getline(inputFile, word))
	{
		ReadDectionary(inputFile, word);
	}

	std::string result = inputWord;

	return result;
}
