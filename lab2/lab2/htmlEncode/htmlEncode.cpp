// htmlEncode.cpp: определяет точку входа для консольного приложения.
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
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&quot;", "\"" },
	{ "&amp;", "&" },
	{ "&apos;", "'" }
};

void FindAndReplace(std::string& subject, std::string const& search, std::string const& replace)
{
	if (search.empty())
	{
		return;
	}
	size_t pos = 0;
	std::string resultStr;
	while (pos < subject.length())
	{
		auto foundPos = subject.find(search, pos);
		resultStr.append(subject, pos, foundPos - pos);
		pos = foundPos;
		if (foundPos != std::string::npos)
		{
			resultStr.append(replace);
			pos += search.length();
		}
	}
	subject = move(resultStr);
}

std::string HtmlDecode(std::string const& html)
{
	std::string result = html;
	for (auto Symbol : Library)
	{
		FindAndReplace(result, Symbol.input, Symbol.output);
	}
	return result;
}

/*массив структур, смиволы начинаются с амперсандов, compare*/
