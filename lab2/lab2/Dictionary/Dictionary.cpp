// Dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef std::map<std::string, std::string> Dictionary;

ifstream OpenFile(const string& inputFileName)
{

	ifstream inputFile(inputFileName);
	inputFile.open(inputFileName);

	if (!inputFile.is_open())
	{
		cout << "Failed to open "
			 << "inputFile"
			 << " for reading\n";
	}
	return inputFile;
}

string Translate(const string& inputWord, const string& inputFileName)
{

	map<string, string> Dictionary{
		{ "", "" }
	};

	//открыть для чтения
	//прочитать и вернуть строку
	//найти нужное слово

	string word, translation;

	Dictionary dictionary;
	OpenFile(inputFileName);
	while (getline(inputFile, word))
	{
		ReadDectionary(inputFile);
	}

	std::string result = inputWord;

	return result;
}
