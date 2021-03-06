// PrimeNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "PrimeNumbers.h"
using namespace std;

vector<bool> GetSieve(int upperBound)
{

	if (upperBound < 0)
	{
		upperBound = 0;
	}

	vector<bool> prime(upperBound + 1, true);

	if (upperBound >= 2)
	{
		prime[2] = true;
	}

	if (upperBound > 2)
	{
		for (int i = 2; i * i <= upperBound; i++)
		{
			if (prime[i])
			{
				int step = (i == 2) ? (2) : (i * 2);

				for (int j = i * i; j <= upperBound; j += step)
				{
					prime[j] = false;
				}
			}
		}
	}
	return prime;
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> primeNumbersSet;

	vector<bool> isPrime = GetSieve(upperBound);
	for (int i = 2; i <= upperBound; i++)
	{
		if (isPrime[i])
		{
			primeNumbersSet.insert(primeNumbersSet.end(), i);
		}
	}
	return primeNumbersSet;
}
