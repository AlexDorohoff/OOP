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

CTime::CTime()
	: m_timestamp(0)
{
}

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if (hours >= HOURS_IN_DAY || minutes >= MINUTES_IN_HOUR || seconds >= SECONDS_IN_MINUTE)
	{
		throw std::invalid_argument("invalid argument \n");
	}
	m_timestamp = SECONDS_IN_HOUR * hours + SECONDS_IN_MINUTE * minutes + seconds;
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
	++m_timestamp;
	if (m_timestamp >= SECONDS_IN_DAY)
	{
		m_timestamp = m_timestamp - SECONDS_IN_DAY;
	}

	return *this;
}

CTime const CTime::operator++(int)
{
	CTime tmpTime(*this);
	++*this;
	return tmpTime;
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
	CTime tmpTime(*this);
	--*this;
	return tmpTime;
}

CTime CTime::operator+(CTime const& time2) const
{
	unsigned sum = m_timestamp + time2.m_timestamp;
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
	return CTime(result);
}

CTime CTime::operator+=(CTime const& time)
{

	m_timestamp += time.m_timestamp;
	return CTime(PreventOverFlowSecond(m_timestamp));
}

CTime CTime::operator-=(CTime const& time)
{
	if (m_timestamp < time.m_timestamp)
	{
		m_timestamp = SECONDS_IN_DAY - (time.m_timestamp - m_timestamp);
	}
	else
	{
		m_timestamp -= time.m_timestamp;
	}
	return CTime(m_timestamp);
}

CTime const CTime::operator*(int const arg) const
{
	unsigned result = m_timestamp * arg;

	return CTime(PreventOverFlowSecond(result));
}

/*
CTime const CTime::operator*(CTime time, int const arg) const
{
	unsigned result = arg * m_timestamp;
	return CTime(result);
}
*/

CTime const CTime::operator/(int const arg) const
{
	if (arg == 0)
	{
		throw std::invalid_argument("Arg can't be a zero");
	}
	else
	{
		return CTime(m_timestamp / arg);
	}
};

CTime CTime::operator*=(int const& time)
{
	m_timestamp *= time;
	return CTime(PreventOverFlowSecond(m_timestamp));
}

int CTime::operator/=(CTime const& time)
{
	m_timestamp /= time.m_timestamp;
	return m_timestamp;
}

bool CTime::operator==(CTime const& time) const
{
	std::cout << m_timestamp << " " << time.m_timestamp;
	return (m_timestamp == time.m_timestamp);
}

bool CTime::operator!=(CTime const& time) const
{
	return (m_timestamp != time.m_timestamp);
}

bool CTime::operator<(CTime const& time) const
{
	return (m_timestamp < time.m_timestamp);
}

bool CTime::operator>(CTime const& time) const
{
	return (m_timestamp > time.m_timestamp);
}

bool CTime::operator<=(CTime const& time) const
{
	return (m_timestamp <= time.m_timestamp);
}

bool CTime::operator>=(CTime const& time) const
{
	return (m_timestamp >= time.m_timestamp);
}
