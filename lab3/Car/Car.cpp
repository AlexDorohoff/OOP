#include "stdafx.h"
#include "Car.h"

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
	else if (IsEngineOn())
	{
		error = "Engine already started \n";
		return false;
	}
}

bool Car::TurnOffEngine()
{
	if (!IsEngineOn())
	{
		error = "engine allready stoped \n";
		return false;
	}

	if (m_speed == 0)
	{
		isEngineTurnOn = false;
		return true;
	}
	else
	{
		error = "Speed is not 0 \n ";
		return false;
	}
	return false;
}

bool Car::SetGear(int gear)
{
	if (!IsEngineOn())
	{
		error = "Failed! Engin is off \n";
		return false;
	}

	if (m_gear == gear)
	{
		error = "Gear EQUAL/n";
		return false;
	}

	if (IsACorrectGear(gear, m_speed))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

int Car::GetGear() const
{
	return m_gear;
}

int Car::GetSpeed() const
{
	return m_speed;
}

bool Car::SetSpeed(int speed)
{
	if (!isEngineTurnOn)
	{
		error = "Engine is off\n";
		return false;
	}

	if (m_speed == speed)
	{
		error = "Speed EQUAL/n";
		return false;
	}

	if (IsACorrectGear(m_gear, speed))
	{
		m_speed = speed;
	}
	else
	{
		error = "Not a correct gear\n";
		return false;
	}
	return true;
}

std::string Car::GetError()
{
	return error;
}
