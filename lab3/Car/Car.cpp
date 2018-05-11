#include "stdafx.h"
#include "Car.h"
/*
bool IsACorrectGear(int gear)
{
	return true;
}
*/
bool Car::IsEngineOn()
{
	return isEngineTurnOn;
}

bool Car::TurnOnEngine()
{
	if (!IsEngineOn())
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

bool Car::TurnOffEngine()
{
	if (m_gear == 0)
	{
		isEngineTurnOn = false;
		return true;
	}
	else
	{
		error = "Gear is not 0 \n";
		return false;
	}
}

bool Car::SetGear(int gear)
{
	if (!IsEngineOn())
	{
		error = "Failed! Engin is off";
		return false;
	}

	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}
}

std::string Car::GetEror()
{
	return error;
}
