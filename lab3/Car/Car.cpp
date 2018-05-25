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

Direction Car::GetDirection() const
{
	if (m_speed == 0)
	{
		return Direction::Stop;
	}
	else if (m_speed < 0)
	{
		return Direction::Backward;
	}
	else
	{
		return Direction::Forward;
	}
}

bool Car::IsEngineOn() const
{
	return m_isEngineTurnOn;
}

bool Car::TurnOnEngine()
{
	if (!IsEngineOn())
	{
		m_isEngineTurnOn = true;
		m_error.clear();
		return true;
	}
	else if (IsEngineOn())
	{
		m_error = "Engine already started \n";
	}
	return false;
}

bool Car::TurnOffEngine()
{
	if (!IsEngineOn())
	{
		m_error = "engine allready stoped \n";
		return false;
	}

	if (m_speed == 0 && m_gear == 0)
	{
		m_isEngineTurnOn = false;
		m_error.clear();
		return true;
	}
	else if (m_speed != 0)
	{
		m_error = "Speed is not 0 \n ";
	}
	else if (m_gear != 0)
	{
		m_error = "Gear is not 0\n";
	}
	return false;
}

bool Car::SetGear(int gear)
{
	if (!IsEngineOn())
	{
		m_error = "Failed! Engin is off \n";
	}

	if (gear == 0)
	{
		m_gear = gear;
		m_error.clear();
		return true;
	}

	if (IsACorrectGear(gear, m_speed) && IsEngineOn())
	{
		if ((gear > 0 && m_speed >= 0) || (gear == -1 && m_speed == 0))
		{
			m_gear = gear;
			m_error.clear();
			return true;
		}
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
	if (!IsEngineOn())
	{
		m_error = "Engine is off\n";
		return false;
	}

	if (m_speed == speed)
	{
		m_error = "Speed EQUAL/n";
	}

	if (m_gear == -1 && GetDirection() == Direction::Stop)
	{
		m_speed = speed * -1;
		m_error.clear();
		return true;
	}

	if (m_gear == 0 && (GetDirection() == Direction::Backward || GetDirection() == Direction::Forward))
	{
		if (m_speed > speed)
		{
			m_speed = speed;
			m_error.clear();
			return true;
		}
		else
		{
			m_error = "This speed not correct for this gear\n";
			return false;
		}
	}

	if (IsACorrectGear(m_gear, speed))
	{
		m_speed = speed;
		m_error.clear();
		return true;
	}
	else
	{
		m_error = "Not a correct gear\n";
	}
	return false;
}

std::string Car::GetError() const
{
	return m_error;
}
