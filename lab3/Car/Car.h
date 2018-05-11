#pragma once
class Car
{
public:
	bool isEngineOn();
	bool turnOnEngine();
	bool turnOffEngine();
	bool setGear(int gear);

private:
	bool isEngineTurnOn = false;
	std::string error;
	int m_speed = 0;
	int m_gear = 0;
};
