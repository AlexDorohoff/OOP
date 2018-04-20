// htmlEncode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void print(std::string const& html)
{
	std::cout << html;
}

struct Symbol
{
	std::string input;
	std::string output;
};

struct Symbols
{
	Symbol less;
	Symbol greater;
	Symbol solidus;
	Symbol ampersand;
	Symbol apostrophe;
};

Symbols Library{

	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&quot;", "\"" },
	{ "&amp;", "&" },
	{ "&apos;", "'" }
};
std::string HtmlDecode(std::string const& html)
{
	size_t pos = 0;
	std::string result;

	while (pos < html.length())
	{
		char item = html[pos];
		if (std::find(Library.begin(), Library.end(), item) != Library.end())
		{
			std::cout << Library[item];
		}

		pos = pos + 1;
	}

	return result;
}

/*массив структур, смиволы начинаются с амперсандов, compare*/
