// Dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

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

Dictionary ReadDictionary(istream& inputFile, Dictionary& dictionary)
{
	string word;
	string translate;
	/*while getline  findWord*/
	getline(inputFile, word);
	getline(inputFile, translate);
	std::cout << word << std::endl;
	std::cout << translate << std::endl;
	return dictionary;
}

string Translate(const string& inputWord, const string& inputFileName)
{

	//открыть для чтения
	//прочитать и вернуть строку
	//найти нужное слово

	string word, translation;
	Dictionary dictionary;

	std::ifstream inputFile;

	inputFile = OpenFile(inputFileName);
	while (getline(inputFile, word))
	{
		ReadDictionary(inputFile, dictionary);
	}

	std::string result = inputWord;

	return result;
}
