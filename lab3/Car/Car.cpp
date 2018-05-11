#include "stdafx.h"
#include "Car.h"

bool Car::isEngineOn()
{
	return engineStatus;
}

bool Car::turnOnEngine()
{
	if (!isEngineOn())
	{
		engineStatus = true;
		return true;
	}
	else
	{
		error = "Engine already started ";
		return false;
	}
}

bool Car::turnOffEngine()
{
	if (isEngineOn())
	{
		engineStatus = false;
		return true;
	}
	else
	{
		return false;
	}
}
