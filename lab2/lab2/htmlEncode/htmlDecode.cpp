// htmlDecode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>

void print(std::string const& html)
{
	std::cout << html;
}

struct Symbol
{
	std::string input;
	std::string output;
};

const std::vector<Symbol> Library{
	{ "&apos;", "'" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&quot;", "\"" },
	{ "&amp;", "&" }
};

void ReplaceString(std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{

	if (searchString == "")
	{
		return;
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
			pos = foundPos + searchString.size();
		}
		else
		{
			break;
		}
	}
	subject = result;
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
