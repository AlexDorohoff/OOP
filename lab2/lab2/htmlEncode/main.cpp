
#include "stdafx.h"
#include "EncodeHtml.h"
#include <string>

int main()
{
	std::string html;

	while (std::getline(std::cin, html))
	{
		HtmlDecode(html);
	}
}
