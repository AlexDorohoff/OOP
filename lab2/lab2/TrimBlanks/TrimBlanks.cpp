#include "stdafx.h"
#include "TrimBlanks.h"

std::string TrimBlanks(const std::string& str)
{
	size_t firstPrinableCharPos = str.find_first_not_of(' ');

	if (firstPrinableCharPos == std::string::npos)
		return {};

	size_t lastPrintableCharPos = str.find_last_not_of(' ');

	return str.substr(firstPrinableCharPos, lastPrintableCharPos - firstPrinableCharPos + 1);
}
