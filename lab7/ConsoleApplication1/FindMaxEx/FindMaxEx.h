#pragma once
#include <functional>
#include <vector>

template <typename T, typename Less>
bool FindMaxEx(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	size_t size = arr.size();
	const T* max = &arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (less(*max, arr[i]))
		{
			max = &arr[i];
		}
	}
	maxValue = *max;
	return true;
}
