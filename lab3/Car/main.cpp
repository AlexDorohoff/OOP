// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "RemoteControl.h"
#include "car.h"

using namespace std;

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
