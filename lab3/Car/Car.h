#pragma once
class Car
{
public:
	bool isEngineOn();
	bool turnOnEngine();
	bool turnOffEngine();

private:
	bool engineStatus = false;
	std::string error;
};
