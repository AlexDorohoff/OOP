// htmlEncode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
void print(std::string const& html)
{
	std::cout << html;
}

std::vector<std::string> Library{
	{ "&lt;", "<" }, { "s&gt", ">" },
	{ "&quot", "\"" }, { "&amp;", "&" },
	{ "&apos;", "'" }

};
std::string HtmlDecode(std::string const& html, std::vector<std::string> Library)
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
