#include "stdafx.h"
#include "../../Catch/catch.hpp"
#include "../Car/Car.h"
#include "../Car/RemoteControl.h"

TEST_CASE("First")
{
	Car car;
	REQUIRE(!car.IsEngineOn());
}
