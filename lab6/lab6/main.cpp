// lab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHttpUrl.h"

std::string ProtocolToString(Protocol protocol)
{
	std::string stringProtocol;
	if (protocol == HTTP)
	{
		stringProtocol = "http";
	}
	if (protocol == HTTPS)
	{
		stringProtocol = "https";
	}

	return stringProtocol;
}

void PrintInfo(CHttpUrl& url)
{
	std::cout << "url: " << url.GetURL() << "\n"
			  << "protocol: " << ProtocolToString(url.GetProtocol()) << "\n"
			  << "domain: " << url.GetDomain() << "\n"
			  << "document: " << url.GetDocument() << "\n"
			  << "port: " << url.GetPort() << "\n";
}

int main()
{
	while (!std::cin.eof())
	{
		std::string inputString;
		std::cin >> inputString;
		if (!inputString.empty())
		{
			try
			{
				CHttpUrl url(inputString);
				PrintInfo(url);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << "\n";
			}
		}
		else
		{
			break;
		}
	}
}
