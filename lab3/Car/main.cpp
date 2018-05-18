// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "RemoteControl.h"
#include "car.h"

using namespace std;

void IsEngineOn(Car& car)
{
	if (car.IsEngineOn())
	{
		cout << "Engin is on \n";
	}
	else if (!car.IsEngineOn())
	{
		cout << "Engin is off \n";
	}
}

void TurnOn(Car& car)
{
	if (car.TurnOnEngine())
	{
		cout << "Engine was started";
	}
	else
	{
		cout << car.GetError();
	}
}

void TurnOff(Car& car)
{
	if (car.TurnOffEngine())
	{
		cout << "Engine is off \n";
	}
}

int main()
{
	string command;
	Car car;
	CDriveControl driveContol(car, cin, cout);
	cout << "Enter command: \n";
	while (!std::cin.eof() && !std::cin.fail())
	{
		cout << "> ";
		if (!driveContol.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
}
