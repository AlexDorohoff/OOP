// lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CTime.h"

int main(int argc, char* argv)
{

	try
	{
		CTime time(23, 59, 59);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	CTime time(11111);
	std::cout << time.GetHours()
			  << " " << time.GetMinutes()
			  << " " << time.GetSeconds();
}
