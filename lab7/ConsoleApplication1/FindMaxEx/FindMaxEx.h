#pragma once
template <typename T, typename Less>

bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	size_t size = arr.size();
	for (size_t i = 0; i < size; i++)
	{
		*maxValue = less(arr[i], *maxValue);
	}

	return *maxValue;
}
