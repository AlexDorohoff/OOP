#pragma once
#include "stdafx.h"
typedef std::map<std::string, std::string> Dictionary;

std::string Translate(const std::string& inputWord, const std::string& inputFileName);
std::ifstream OpenFile(const std::string& inputFileName);
Dictionary ReadDictionary(std::istream& inputFile, Dictionary& dictionary);
