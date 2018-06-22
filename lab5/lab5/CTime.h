#pragma once
// ������ (0-59)

class CTime

{

public:
	// �������������� ����� �������� ����������� �����, ����� � ������

	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// �������������� ����� ����������� ������ ����� ��������

	CTime(unsigned timeStamp = 0);

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

	CTime operator*(CTime const* scalar) const;

private:
	unsigned m_timestamp = 0;
};
