#include "stdafx.h"
#include "CTime.h"

constexpr unsigned SECONDS_IN_HOUR = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned SECONDS_IN_DAY = 86400;

constexpr unsigned HOURS_IN_DAY = 24;
constexpr unsigned MINUTES_IN_HOUR = 60;

unsigned PreventOverFlowSecond(unsigned timeStamp)
{
	return timeStamp % SECONDS_IN_DAY;
}

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if (hours > HOURS_IN_DAY || minutes > MINUTES_IN_HOUR || seconds > SECONDS_IN_MINUTE)
	{
		throw std::invalid_argument("invalid argument \n");
	}
	m_timestamp = SECONDS_IN_HOUR * hours + SECONDS_IN_MINUTE * minutes + seconds;
	std::cout << "timestamp : " << m_timestamp << "end\n";
}

unsigned CTime::GetHours() const
{
	return m_timestamp / SECONDS_IN_HOUR;
}

unsigned CTime::GetMinutes() const
{
	return m_timestamp / SECONDS_IN_MINUTE - (m_timestamp / SECONDS_IN_HOUR) * SECONDS_IN_MINUTE;
}

unsigned CTime::GetSeconds() const
{
	return m_timestamp % SECONDS_IN_MINUTE;
};

CTime::CTime(unsigned timeStamp)
{
	if (timeStamp >= SECONDS_IN_DAY)
	{
		throw std::invalid_argument("invalid argument 2\n");
	}
	m_timestamp = timeStamp;
}

unsigned CTime::GetM_Time() const
{
	return m_timestamp;
}

CTime& CTime::operator++()
{
	if (m_timestamp >= SECONDS_IN_DAY)
	{
		m_timestamp = m_timestamp - SECONDS_IN_DAY;
	}
	else
	{
		++m_timestamp;
	}
	return *this;
}

CTime const CTime::operator++(int)
{
	// создаем копию, выполняем предынкремент и возвращаем копию
	//CCounter tmpCopy(*this);
	//++*this;
	//return tmpCopy;
	unsigned tmpTime = m_timestamp;
	++m_timestamp;
	if (m_timestamp >= SECONDS_IN_DAY)
	{
		m_timestamp = m_timestamp - SECONDS_IN_DAY;
	}
	return CTime(tmpTime);
}

CTime& CTime::operator--()
{
	if (m_timestamp == 0)
	{
		m_timestamp = SECONDS_IN_DAY - 1;
	}
	else
	{
		--m_timestamp;
	}
	return *this;
}

CTime const CTime::operator--(int)
{
	// создаем копию, выполняем предынкремент и возвращаем копию
	//CCounter tmpCopy(*this);
	//++*this;
	//return tmpCopy;
	unsigned tmpTime = m_timestamp;
	if (m_timestamp == 0)
	{
		tmpTime = SECONDS_IN_DAY - 1;
	}
	else
	{
		--m_timestamp;
	}
	return tmpTime;
}

CTime CTime::operator+(CTime const& time2) const
{
	unsigned sum = m_timestamp + time2.m_timestamp;
	std::cout << "sum: " << sum << "\n";
	return CTime(PreventOverFlowSecond(sum));
}

CTime CTime::operator-(CTime const& time2) const
{
	unsigned result = 0;
	if (m_timestamp < time2.m_timestamp)
	{
		result = SECONDS_IN_DAY - (time2.m_timestamp - m_timestamp);
	}
	else
	{
		result = m_timestamp - time2.m_timestamp;
	}
	return result;
}
