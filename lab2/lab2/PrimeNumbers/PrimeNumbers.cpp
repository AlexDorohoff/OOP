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
	prime[0] = prime[1] = false;
	for (int i = 2; i <= upperBound; ++i)
	{
		if (prime[i])
			if (i * 1ll * i <= upperBound)
				for (int j = i * i; j <= upperBound; j += i)
					prime[j] = false;
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
