#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../Car/Car.h"
#include "../Car/RemoteControl.h"

void TestCommandHandler(Car& car, const std::string& inputRequest, const std::string& outputEcho)
{
	std::stringstream input, output;
	input = std::stringstream();
	output = std::stringstream();
	CDriveControl DriveControl(car, input, output);

	CHECK(input << inputRequest);
	CHECK(DriveControl.HandleCommand());
	CHECK(input.eof());
	CHECK(output.str() == outputEcho);
}

TEST_CASE("GetStarted")
{
	Car car;
	std::string input = "EngineOn";
	std::string output = "Engine is turned on\n";
	TestCommandHandler(car, input, output);
}

TEST_CASE("GetOff")
{
	Car car;
	car.TurnOnEngine();
	std::string input = "EngineOff";
	std::string output = "Engine is turned off\n";
	TestCommandHandler(car, input, output);
}

TEST_CASE("can GetInfo on car")
{

	Car car;
	TestCommandHandler(car, "Info",
		"Engine is Off\nGear : 0\nSpeed : 0\nDirection : stop\n");
}

TEST_CASE("Can't set speed on off engine")
{

	Car car;
	TestCommandHandler(car, "SetSpeed 10", "Engine is off\nSpeed not change\n");
}

TEST_CASE("Can't set speed then engine is on whithout correct gear")
{

	Car car;
	car.TurnOnEngine();
	TestCommandHandler(car, "SetSpeed 10", "Not a correct gear\nSpeed not change\n");

	car.SetGear(1);
	TestCommandHandler(car, "SetSpeed 60", "Not a correct gear\nSpeed not change\n");

	TestCommandHandler(car, "SetSpeed 10", "Set speed 10\n");
}

TEST_CASE("Can't set incorrect gear")
{
	Car car;
	car.TurnOnEngine();
	TestCommandHandler(car, "SetGear 2", "Gear not set\n");

	car.SetGear(1);
	car.SetSpeed(20);
	TestCommandHandler(car, "SetGear 4", "Gear not set\n");

	TestCommandHandler(car, "SetGear -1", "Gear not set\n");

	TestCommandHandler(car, "SetGear 2", "select gear: 2\n");
}

TEST_CASE("Can't set gear out of range")
{
	Car car;
	car.TurnOnEngine();

	TestCommandHandler(car, "SetGear -2", "Use one between '-1' and '5'\n");
	TestCommandHandler(car, "SetGear 6", "Use one between '-1' and '5'\n");
}

TEST_CASE("can't select an incorrect speed")
{
	Car car;
	TestCommandHandler(car, "SetSpeed a", "Invalid speed\n");
};

TEST_CASE("can't select a nagative speed")
{
	Car car;
	TestCommandHandler(car, "SetSpeed -2", "Speed can not be negative\n");
};
