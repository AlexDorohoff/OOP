#include "stdafx.h"
#include "RemoteControl.h"
#include "Car.h"
#include <iostream>

using namespace std;
using namespace placeholders;

CDriveControl::CDriveControl(Car& car, istream& input, ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "EngineOn", bind(&CDriveControl::EngineOn, this, placeholders::_1) },
		  { "EngineOff", bind(&CDriveControl::EngineOff, this, placeholders::_1) },
		  { "Info", bind(&CDriveControl::Info, this, placeholders::_1) },
		  { "SetGear", bind(&CDriveControl::SetGear, this, placeholders::_1) },
		  { "SetSpeed", bind(&CDriveControl::SetSpeed, this, placeholders::_1) } })
{
}

bool CDriveControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CDriveControl::EngineOn(istream&)
{
	if (m_car.TurnOnEngine())
	{
		m_output << "Engine is turned on\n";
	}
	else
	{
		m_output << m_car.GetError();
	}
	return true;
}

bool CDriveControl::EngineOff(istream&)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine is turned of\n";
	}
	else
	{
		m_output << m_car.GetError() << "\n";
	}
	return true;
}

bool CDriveControl::Info(istream&) const
{
	string enginInfo = (m_car.IsEngineOn() ? "Engine is On \n" : "Engine is Off \n");
	m_output << enginInfo;

	int gearInfo = (m_car.GetGear());
	m_output << "Gear : " << gearInfo << "\n";

	int speedInfo = (m_car.GetSpeed());
	m_output << "Speed : " << speedInfo << "\n";
	return true;
}

bool TakeArg(string& input, int& arg)
{
	arg = stoi(input);
	/*
	if (gear << stoi(input))
	{
		cout << gear;
	}*/
	return true;
}

bool CDriveControl::SetGear(istream& args)
{
	int gear;
	string input;
	args >> input;
	if (TakeArg(input, gear))
	{
		if ((gear < -1) || (gear > 5))
		{
			m_output << "Use one between '-1' and '5' \n";
		}
		else if (m_car.SetGear(gear))
		{
			m_output << "select gear: " << gear << "\n";
		}
		else
		{
			m_output << m_car.GetError();
			m_output << "Gear not change\n";
		}
	}
	return true;
}

bool CDriveControl::SetSpeed(istream& args)
{
	int speed;
	string input;
	args >> input;
	if (TakeArg(input, speed))
	{
		if (speed < 0)
		{
			cout << "Error, speed can't be with minus\n";
		}
		else if (m_car.SetSpeed(speed))
		{
			m_output << "Set speed " << speed << "\n";
		}
		else
		{
			m_output << m_car.GetError();
			m_output << "Speed not change\n";
		}
	}
	return true;
}
