#pragma once

enum class Direction
{
	Backward,
	Stop,
	Forward
};

class Car
{
public:
	bool IsEngineOn() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetSpeed() const;
	int GetGear() const;
	std::string GetError() const;
	Direction GetDirection() const;

private:
	bool isEngineTurnOn = false;
	std::string error;
	int m_speed = 0;
	int m_gear = 0;
};
