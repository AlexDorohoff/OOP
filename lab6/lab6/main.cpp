// lab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHttpUrl.h"

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
				url.PrintInfo();
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
