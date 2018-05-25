// CarTests.cpp: определяет точку входа для консольного приложения.
//
#define CATCH_CONFIG_MAIN

#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../Car/Car.h"
#include <functional>
#include <sstream>

void ExpectOperationSuccess(Car& car, const std::function<bool(Car& car)>& op, bool expectedEngineCondition, int expectedGear, int expectedSpeed, Direction expectedDirection)
{
	CHECK(op(car));
	CHECK(car.IsEngineOn() == expectedEngineCondition);
	CHECK(car.GetGear() == expectedGear);
	CHECK(car.GetSpeed() == expectedSpeed);
	CHECK(car.GetDirection() == expectedDirection);
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
	CHECK(clone.GetSpeed() == car.GetSpeed());
}

TEST_CASE("Engine is turned off by default")
{
	Car car;
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("off engine is turned on")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.IsEngineOn());
}
TEST_CASE("on engine is turnet off")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("turned on engine can not turn on")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(!car.TurnOnEngine());
	REQUIRE(car.IsEngineOn());
}

TEST_CASE("turned off engine can not turn off")
{
	Car car;
	car.TurnOffEngine();
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("Set gear on turned on Engine")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(1));
	REQUIRE(!car.TurnOffEngine());
}

TEST_CASE("Can not set gear on OffEngine")
{
	Car car;
	car.TurnOffEngine();
	REQUIRE(!car.SetGear(1));
}

TEST_CASE("can not set speed on onEngine without gear")
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

TEST_CASE("Can not select gear to move forward after move backward")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(car.SetGear(-1));
	REQUIRE(car.SetSpeed(20));
	REQUIRE(!car.SetGear(1));
}

TEST_CASE("engine is turned off by default")
{
	//изначально двигатель выключен
	Car car;

	ExpectOperationSuccess(car, [](Car& car) { return !car.IsEngineOn(); }, false /*Is engine turn on*/, 0 /*gear*/, 0 /*speed*/, Direction::Stop /*direction*/);
}

TEST_CASE("Can ")
