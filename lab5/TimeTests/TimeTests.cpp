// TimeTests.cpp: определяет точку входа для консольного приложения.
//
#include "../../Catch/catch.hpp"
#include "../lab5/CTime.h"

TEST_CASE("Get parameters")
{
	CTime time(20, 20, 20);
	REQUIRE(time.GetHours() == 20);
	REQUIRE(time.GetMinutes() == 20);
	REQUIRE(time.GetSeconds() == 20);
}

TEST_CASE("Get seconds")
{
	CTime time(10, 10, 10);
	REQUIRE(time.GetM_Time() == 36610);
}

TEST_CASE("get hours from seconds")
{
	CTime time(3700);
	REQUIRE(time.GetHours() == 1);
}

TEST_CASE("get minutes from seconds after get a hours")
{
	CTime time(3700);
	//после того как вычтется час из секунд останется чуть больше одной минуты
	REQUIRE(time.GetMinutes() == 1);
}

TEST_CASE("get seconds from seconds after get a minutes")
{
	CTime time(3700);
	REQUIRE(time.GetSeconds() == 40);
}

TEST_CASE("can dicrement a time")
{
	CTime time(0);
	--time;
	REQUIRE(time.GetM_Time() == 86399);

	CTime time1(0);
	time1--;
	REQUIRE(time1.GetM_Time() == 0);
}

TEST_CASE("can increment a date")
{
	CTime time(0);
	++time;
	REQUIRE(time.GetM_Time() == 1);

	CTime time1(0);
	time1++;
	REQUIRE(time1.GetM_Time() == 0);
}
