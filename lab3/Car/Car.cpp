#include "stdafx.h"
#include "Car.h"

bool Car::isEngineOn()
{
	return isEngineTurnOn;
}

bool Car::turnOnEngine()
{
	if (!isEngineOn())
	{
		isEngineTurnOn = true;
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
	if (isEngineOn() && (m_gear == 0))
	{
		isEngineTurnOn = false;
		return true;
	}
	else
	{
		std::cout << "Gear is not 0 \n";
		return false;
	}
}

bool Car::setGear(int gear)
{
	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}

	if (!isEngineOn())
	{
		error = "Failed! Engin is off";
		return false;
	}
}
