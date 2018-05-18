// CarTests.cpp: определяет точку входа для консольного приложения.
//
#define CATCH_CONFIG_MAIN

#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../Car/Car.h"
#include <functional>
#include <sstream>

void ExpectOperationSuccess(Car& car, const std::function<bool(Car& car)>& op, bool expectedEngineCondition, int expectedGear, int expectedSpeed)
{
	CHECK(op(car));
	CHECK(car.IsEngineOn() == expectedEngineCondition);
	CHECK(car.GetGear() == expectedGear);
	CHECK(car.GetSpeed() == expectedSpeed);
}

void ExpectOperationFailure(const Car& car, const std::function<bool(Car& car)>& op)
{
	auto clone(car); // сделали клон объекта
	CHECK(!op(clone)); // ожидаем, что операция завершится неуспешно (передаем клон)
		// проверяем, что после выполнения операции состояние клона не отличается от оригинала
		// (операция в случае неудачи оставляет объект в состоянии, в котором он пребывал до операции)
	CHECK(clone.IsEngineOn() == car.IsEngineOn());
	CHECK(clone.GetGear() == car.GetGear());
	CHECK(clone.GetSpeed() == car.GetSpeed());
}

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
	REQUIRE(car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("Set gear on onEngine")
{
	Car car;
	car.TurnOnEngine();
	car.SetGear(1);
	REQUIRE(!car.TurnOffEngine());
}

TEST_CASE("Set gear on OffEngine")
{
	Car car;
	car.TurnOffEngine();
	REQUIRE(!car.SetGear(1));
}

TEST_CASE("Set speed on onEngine without gear")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(!car.SetSpeed(10));
}

TEST_CASE("Set speed on onEngine with gear")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(car.SetGear(1));
	REQUIRE(car.SetSpeed(10));
}
