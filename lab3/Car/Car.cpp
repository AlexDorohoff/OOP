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
		return true; // как правильно сделать передачу параметра, чтобы не проваливаться на уровень выше и не выводить uknown
	}
	return false;
}

bool Car::TurnOffEngine()
{
	if (!IsEngineOn())
	{
		error = "engine allready stoped \n";
	}

	if (m_speed == 0 && m_gear == 0)
	{
		isEngineTurnOn = false;
		return true;
	}
	else if (m_speed != 0)
	{
		error = "Speed is not 0 \n ";
	}
	else if (m_gear != 0)
	{
		error = "Gear is not 0\n";
	}
	return false;
}

bool Car::SetGear(int gear)
{
	if (!IsEngineOn())
	{
		error = "Failed! Engin is off \n";
	}

	if (m_gear == gear)
	{
		error = "Gear EQUAL/n";
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
	}

	if (m_speed == speed)
	{
		error = "Speed EQUAL/n";
	}

	if (m_gear == 0)
	{
		error = "Gear is not on\n";
	}

	if (IsACorrectGear(m_gear, speed))
	{
		m_speed = speed;
		return true;
	}
	else
	{
		error = "Not a correct gear\n";
	}
	return false;
}

std::string Car::GetError()
{
	return error;
}
