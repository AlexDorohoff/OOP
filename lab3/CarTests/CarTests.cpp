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

TEST_CASE("Can stop the car after backward direction on gear 0;")
{
	//изначально двигатель выключен
	Car car;
	car.TurnOnEngine();
	car.SetGear(-1);
	REQUIRE(car.SetSpeed(20));
	REQUIRE(car.SetGear(0));
	REQUIRE(car.SetSpeed(0));
	ExpectOperationSuccess(car, [](Car& car) { return car.IsEngineOn(); }, true /*Is engine turn on*/, 0 /*gear*/, 0 /*speed*/, Direction::Stop /*direction*/);
}

TEST_CASE("Can stop the car after forward direction on rear 0")
{
	Car car;
	car.TurnOnEngine();
	car.SetGear(1);
	REQUIRE(car.SetSpeed(20));
	REQUIRE(car.SetGear(0));
	REQUIRE(car.SetSpeed(0));
	ExpectOperationSuccess(car, [](Car& car) { return car.IsEngineOn(); }, true /*Is engine turn on*/, 0 /*gear*/, 0 /*speed*/, Direction::Stop /*direction*/);
}

TEST_CASE("then engine is on, can select only the relevant gear rate")
{
	Car car;
	car.TurnOnEngine();

	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(-1); }, true /*Is engine turn on*/, -1 /*gear*/, 0 /*speed*/, Direction::Stop /*direction*/);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(1); }, true /*Is engine turn on*/, 1 /*gear*/, 0 /*speed*/, Direction::Stop /*direction*/);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(0); }, true /*Is engine turn on*/, 0 /*gear*/, 0 /*speed*/, Direction::Stop /*direction*/);

	ExpectOperationFailure(car, [](Car& car) { return car.SetGear(2); });
	ExpectOperationFailure(car, [](Car& car) { return car.SetGear(-2); });
	ExpectOperationFailure(car, [](Car& car) { return car.SetGear(6); });

	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(-1); }, true, -1, 0, Direction::Stop);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(10); }, true, -1, -10, Direction::Backward);
	ExpectOperationFailure(car, [](Car& car) { return car.SetGear(1); });
	ExpectOperationFailure(car, [](Car& car) { return car.SetGear(-2); });

	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(0); }, true, 0, -10, Direction::Backward);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(0); }, true, 0, 0, Direction::Stop);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(1); }, true, 1, 0, Direction::Stop);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(20); }, true, 1, 20, Direction::Forward);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(2); }, true, 2, 20, Direction::Forward);

	ExpectOperationFailure(car, [](Car& car) { return car.SetGear(-1); });

	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(40); }, true, 2, 40, Direction::Forward);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(3); }, true, 3, 40, Direction::Forward);

	ExpectOperationFailure(car, [](Car& car) { return car.SetGear(1); });

	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(50); }, true, 3, 50, Direction::Forward);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(4); }, true, 4, 50, Direction::Forward);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(60); }, true, 4, 60, Direction::Forward);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetGear(5); }, true, 5, 60, Direction::Forward);
	ExpectOperationFailure(car, [](Car& car) { return car.SetSpeed(160); });
};

TEST_CASE("Can slow down speed on 0 gear, direction::backward")
{
	Car car;
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(10);
	car.SetGear(0);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(5); }, true, 0, -5, Direction::Backward);
	ExpectOperationFailure(car, [](Car& car) { return car.SetSpeed(20); });
}

TEST_CASE("Can slow down speed on 0 gear, direction::forward")
{
	Car car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(10);
	car.SetGear(0);
	ExpectOperationSuccess(car, [](Car& car) { return car.SetSpeed(5); }, true, 0, 5, Direction::Forward);
	ExpectOperationFailure(car, [](Car& car) { return car.SetSpeed(20); });
}

TEST_CASE("Clear error mesage after success")
{
	Car car; // set gear on offEngine
	REQUIRE(!car.SetGear(1));
	REQUIRE(car.GetError() != "");
	//set gear normaly
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(1));
	REQUIRE(car.GetError() == "");
	REQUIRE(car.SetGear(0));
	//set speed on off engine
	REQUIRE(car.TurnOffEngine());
	REQUIRE(!car.SetSpeed(10));
	REQUIRE(car.GetError() != "");
	//set speed normaly
	REQUIRE(car.TurnOnEngine());
	REQUIRE(!car.SetSpeed(10));
	REQUIRE(car.GetError() != "");

	//set not correct speed
	REQUIRE(car.SetGear(1));
	REQUIRE(!car.SetSpeed(40));
	REQUIRE(car.GetError() != "");

	REQUIRE(car.SetSpeed(10));
	REQUIRE(car.GetError() == "");
	car.SetGear(0);

	//Turn off wile car mooving
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(car.GetError() != "");

	REQUIRE(car.SetSpeed(0));
	REQUIRE(car.TurnOffEngine());
	REQUIRE(car.GetError() == "");

	//Turn off offEngine
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(car.GetError() != "");

	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.GetError() == "");

	//Set not correct gear on all directions
	//forward
	REQUIRE(car.SetGear(1));
	REQUIRE(car.SetSpeed(10));
	REQUIRE(!car.SetGear(-1));
	//do not set any error message

	REQUIRE(car.GetError() == "");
	REQUIRE(car.SetSpeed(0));
	REQUIRE(car.SetGear(-1));
	REQUIRE(car.GetError() == "");

	//backward
	REQUIRE(car.SetGear(-1));
	REQUIRE(car.SetSpeed(10));
	REQUIRE(!car.SetGear(1));
	//do not set any error message

	REQUIRE(car.GetError() == "");
	REQUIRE(car.SetSpeed(0));
	REQUIRE(car.SetGear(1));
	REQUIRE(car.GetError() == "");
}
