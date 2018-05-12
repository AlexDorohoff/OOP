#include "stdafx.h"
#include "Car.h"
/*
bool IsACorrectGear(int gear, unsigned int speed)
{
	if ((gear == -1 && speed >= 0 && speed <= 20)
		|| (gear == 1 && speed >= 0 && speed <= 30)
		|| (gear == 2 && speed >= 20 && speed <= 50)
		|| (gear == 3 && speed >= 30 && speed <= 60)
		|| (gear == 4 && speed >= 40 && speed <= 90)
		|| (gear == 5 && speed >= 50 && speed <= 150))
	{
		return true;
	}
	else
	{
		return false;
	}
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
		std::cout << "staring \n";
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
/*
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

	if (IsACorrectGear(gear))
	{
		m_gear = gear;
	}
}

bool Car::SetSpeed()
{
}
*/
std::string Car::GetEror()
{
	return error;
}
