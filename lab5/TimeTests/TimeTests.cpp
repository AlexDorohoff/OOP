// TimeTests.cpp: определяет точку входа для консольного приложения.
//
#include "../../Catch/catch.hpp"
#include "../lab5/CTime.h"
#include "../lab5/stdafx.h"

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

TEST_CASE("can increment a date")
{
	CTime time(0);
	++time;
	REQUIRE(time.GetM_Time() == 1);

	CTime time1(86399);
	time1++;
	REQUIRE(time1.GetM_Time() == 0);
}

TEST_CASE("can dicrement a time")
{
	CTime time(0);
	--time;
	REQUIRE(time.GetM_Time() == 86399);

	CTime time1(0);
	time1--;
	REQUIRE(time1.GetM_Time() == 86399);
}

TEST_CASE("You can sum time")
{
	CTime time1(14, 30, 25);
	CTime time2(03, 18, 44);

	CTime totalTime = time1 + time2;

	CHECK(totalTime.GetM_Time() == 64149);

	CTime time3(86399);
	CTime time4(1);

	CTime totalTime2 = time3 + time4;

	CHECK(totalTime2.GetM_Time() == 0);
}

TEST_CASE("You can sub time")
{
	CTime time1(00, 00, 01);
	CTime time2(00, 00, 10);

	CTime totalTime = time1 - time2;

	CHECK(totalTime.GetM_Time() == 86391);

	CTime time3(10, 10, 10);
	CTime time4(00, 00, 10);

	CTime totalTime2 = time1 - time2;

	CHECK(totalTime2.GetM_Time() == 86391);
}

TEST_CASE("You can addition assignment time")
{
	CTime time1(00, 00, 01);
	CTime time2(00, 00, 10);

	time1 += time2;

	CHECK(time1.GetM_Time() == 11);
}

TEST_CASE("You can subtraction assignment time")
{
	CTime time1(00, 00, 01);
	CTime time2(00, 00, 10);

	time1 -= time2;

	CHECK(time1.GetM_Time() == 86391);

	CTime time3(100);
	CTime time4(20);
	time3 -= time4;
	CHECK(time3.GetM_Time() == 80);
}

TEST_CASE("Can multiple TimeStamp")
{
	CTime time(02, 02, 02);
	CTime result = time * 2;
	CHECK(result.GetM_Time() == 14644);
	CHECK(result.GetHours() == 4);
	CHECK(result.GetMinutes() == 4);
	CHECK(result.GetSeconds() == 4);

	CTime time2(22, 22, 22);
	CTime result2 = time2 * 2;
	CHECK(result2.GetM_Time() == 74684);
	CHECK(result2.GetHours() == 20);
	CHECK(result2.GetMinutes() == 44);
	CHECK(result2.GetSeconds() == 44);
}

TEST_CASE("Can division timestamp")
{
	CTime time(01, 00, 00);
	CTime result = time / 2;
	CHECK(result.GetM_Time() == 1800);
	CHECK(result.GetHours() == 0);
	CHECK(result.GetMinutes() == 30);
	CHECK(result.GetSeconds() == 0);

	CTime time2(22, 22, 22);
	CTime result2 = time2 / 2;
	CHECK(result2.GetM_Time() == 40271);
	CHECK(result2.GetHours() == 11);
	CHECK(result2.GetMinutes() == 11);
	CHECK(result2.GetSeconds() == 11);

	CTime time3(100);
	int arg = 0;
	CHECK_THROWS(time3 / arg);

	CHECK((time2 / time3) == 805);
	CHECK((time3 /= 2).GetSeconds() == 50);
}

TEST_CASE("Multiplication assignment")
{
	CTime time(100);
	int arg = 2;
	time *= arg;
	CHECK(time.GetM_Time() == 200);
}

TEST_CASE("Division assignment")
{
	CTime time1(100);
	time1 /= 2;
	CHECK(time1.GetM_Time() == 50);

	CTime time3(10);
	time3 /= 2;
	CHECK(time3.GetM_Time() == 5);
}

TEST_CASE("Can compare taimestamp")
{
	CTime time1(100);
	CTime time2(50);
	CTime time3(100);
	bool temp = time1 == time2;
	CHECK((time1 == time3));
	CHECK(!(time1 == time2));
	CHECK((time1 != time2));
	CHECK(!(time1 == time2));

	CHECK((time1 > time2));
	CHECK(!(time1 > time3));
	CHECK(!(time2 > time1));

	CHECK((time2 < time1));
	CHECK(!(time1 < time2));
	CHECK(!(time1 < time2));

	CHECK(time1 >= time3);
	CHECK(time1 >= time3);
	CHECK(!(time2 >= time1));
	CHECK(time2 <= time3);
	CHECK(time1 <= time1);
	CHECK(!(time1 <= time2));
}

TEST_CASE("Try to send a 24:00:00")
{
	CHECK_THROWS(CTime(24, 60, 60));
	CHECK_THROWS(CTime(86400 + 10));
}

TEST_CASE("<<")
{
	CTime time(100);
	std::ostream out(time.GetM_Time());
	std::cout << time;
}
