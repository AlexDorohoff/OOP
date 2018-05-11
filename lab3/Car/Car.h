#pragma once
class Car
{
public:
	bool IsEngineOn();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	std::string GetEror();
	bool IsACorrectGear();

private:
	bool isEngineTurnOn = false;
	std::string error;
	int m_speed = 0;
	int m_gear = 0;
};
