#pragma once
// секунд (0-59)

class CTime

{

public:
	// инициализирует время заданным количеством часов, минут и секунд

	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// инициализирует время количеством секунд после полуночи

	CTime(unsigned timeStamp = 0);

	// возвращает количество часов

	unsigned GetHours() const;

	// возвращает количество минут

	unsigned GetMinutes() const;

	// возвращает количество секунд

	unsigned GetSeconds() const;

	unsigned GetM_Time() const;

	CTime& operator++();
	CTime const operator++(int);

	CTime& operator--();
	CTime const operator--(int);

	CTime operator+(CTime const& time2) const;
	CTime operator-(CTime const& time2) const;

	CTime operator+=(CTime const& time);
	CTime operator-=(CTime const& time);

	CTime operator*(CTime const* scalar) const;

private:
	unsigned m_timestamp = 0;
};
