// Dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

std::string Translate(const std::string& inputWord)
{
	std::string result = inputWord;
	std::cout << result;
	return result;
}
