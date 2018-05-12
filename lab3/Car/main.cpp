// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
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
		cout << car.GetEror();
	}
}

int main()
{
	string command;
	Car car;
	cout << "Enter command: \n>";
	while (getline(cin, command))
	{
		transform(command.begin(), command.end(), command.begin(), tolower);
		if (command == "engine is on?")
		{
			IsEngineOn(car);
		}

		if (command == "start engine")
		{
			TurnOn(car);
		}
	}
}
