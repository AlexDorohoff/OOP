// CMyArrayTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ConsoleApplication1/CMyArray.h"
#include "iostream"

using namespace std;

struct ArrayItem
{
	ArrayItem(int value = 0)
		: value(value)
	{
	}
	int value;
};

struct EmptyStringArray
{
	CMyArray<ArrayItem> arr;
};

TEST_CASE("initially the size is zero")
{
	CMyArray<ArrayItem> arr;
	CHECK(arr.GetSize() == 0);
};

TEST_CASE("initially the capacity is zero")
{
	CMyArray<ArrayItem> arr;
	CHECK(arr.GetCapacity() == 0);
};

TEST_CASE("increases the size and capacity after adding an element")
{
	CMyArray<ArrayItem> arr;

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 1);
	CHECK(arr.GetCapacity() == 1);

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 2);
	CHECK(arr.GetCapacity() == 2);

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 3);
	CHECK(arr.GetCapacity() == 4);

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 4);
	CHECK(arr.GetCapacity() == 4);
}
