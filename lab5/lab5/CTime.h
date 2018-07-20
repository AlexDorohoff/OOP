#pragma once
// ������ (0-59)

class CTime

{

public:
	CTime();
	// �������������� ����� �������� ����������� �����, ����� � ������

	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// �������������� ����� ����������� ������ ����� ��������

	explicit CTime(unsigned timeStamp = 0);

	// ���������� ���������� �����

	unsigned GetHours() const;

	// ���������� ���������� �����

	unsigned GetMinutes() const;

	// ���������� ���������� ������

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
