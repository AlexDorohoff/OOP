// htmlDecode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>

struct Symbol
{
	std::string input;
	std::string output;
};

void print(std::string const& html)
{
	std::cout << html;
}

const std::vector<Symbol> Library{
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&quot;", "\"" },
	{ "&amp;", "&" },
	{ "&apos;", "'" }
};

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

std::string HtmlDecode(std::string const& html)
{
	std::string result = html;
	for (auto Symbol : Library)
	{
		ReplaceString(result, Symbol.input, Symbol.output);
	}
	return result;
}

/*массив структур, смиволы начинаются с амперсандов, compare*/
