// CarTests.cpp: определяет точку входа для консольного приложения.
//
#define CATCH_CONFIG_MAIN

#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../Car/Car.h"

TEST_CASE("The new car is turn off engine")
{
	Car car;
	REQUIRE(!car.isEngineOn());
}

TEST_CASE("Turn on engine")
{
	Car car;
	REQUIRE(car.turnOnEngine());
	REQUIRE(car.isEngineOn());
}
TEST_CASE("Turn off engine")
{
	Car car;
	car.turnOnEngine();
	REQUIRE(car.turnOffEngine());
	REQUIRE(!car.isEngineOn());
}

TEST_CASE("Turn On engineIsOn=True engine")
{
	Car car;
	car.turnOnEngine();
	REQUIRE(!car.turnOnEngine());
	REQUIRE(car.isEngineOn());
}

TEST_CASE("Turn off engine is off")
{
	Car car;
	car.turnOffEngine();
	REQUIRE(!car.turnOffEngine());
	REQUIRE(!car.isEngineOn());
}

TEST_CASE("Set gear on onEngine")
{
	Car car;
	car.turnOnEngine();
	car.setGear(1);
	REQUIRE(car.turnOffEngine());
}

TEST_CASE("Set gear on OffEngine")
{
	Car car;
	car.turnOffEngine();
	REQUIRE(!car.setGear(1));
}
