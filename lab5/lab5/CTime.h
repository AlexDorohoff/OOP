#pragma once
// секунд (0-59)

class CTime

{

public:
	CTime();
	// инициализирует время заданным количеством часов, минут и секунд

	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// инициализирует время количеством секунд после полуночи

	explicit CTime(unsigned timeStamp = 0);

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

	//CTime const operator*(int arg, CTime const& time);

	CTime const operator*(int const arg) const;
	CTime const operator/(int const arg) const;
	int operator/(CTime const& time) const;

	CTime operator*=(int const& time);
	CTime operator/=(int const& time);

	bool operator==(CTime const& time) const;
	bool operator!=(CTime const& time) const;

	bool operator<(CTime const& time) const;
	bool operator>(CTime const& time) const;

	bool operator<=(CTime const& time) const;
	bool operator>=(CTime const& time) const;

	friend std::ostream& operator<<(std::ostream& os, const CTime& time);
	friend std::istream& operator>>(std::istream& is, const CTime& time);

private:
	unsigned m_timestamp = 0;
};
