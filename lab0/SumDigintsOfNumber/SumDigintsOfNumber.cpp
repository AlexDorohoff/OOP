// SumDigintsOfNumber.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"

int SumDigits(int i)
{
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0
	while (i != 0)
	{
	    sum += i % 10;
		i /= 10;
	}
	return sum;
};

int main() 
{
	int n;
	n = 0;
	for (int i = 1; i <= 1000; i++)
	{
	    	n = SumDigits(i);
			if (i % n == 0) 
			{
				std::cout << i << " ";
			}
	}
};

