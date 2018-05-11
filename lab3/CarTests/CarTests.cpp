// CarTests.cpp: определяет точку входа для консольного приложения.
//
#define CATCH_CONFIG_MAIN

#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../Car/Car.h"

TEST_CASE("The new car is turn off engine")
{
	Car car;
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("Turn on engine")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.IsEngineOn());
}
TEST_CASE("Turn off engine")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("Turn On engineIsOn=True engine")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(!car.TurnOnEngine());
	REQUIRE(car.IsEngineOn());
}

TEST_CASE("Turn off engine is off")
{
	Car car;
	car.TurnOffEngine();
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("Set gear on onEngine")
{
	Car car;
	car.TurnOnEngine();
	car.SetGear(1);
	REQUIRE(car.TurnOffEngine());
}

TEST_CASE("Set gear on OffEngine")
{
	Car car;
	car.TurnOffEngine();
	REQUIRE(!car.SetGear(1));
}
