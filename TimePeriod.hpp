#pragma once
#include <iostream>
#include <fstream>

class TimePeriod {

private:
	int day;
	int month;
	int year;

public:

	TimePeriod();	 // default 1999-01-01
	TimePeriod(const int day, const int month, const int year);

	const int dayGetter() const;
	const int monthGetter() const;
	const int yearGetter() const;

	bool leapYearChecker(int year) const;
	bool isValid(const int, const int, const int) const;

	friend bool operator==(const TimePeriod&, const TimePeriod&);
	friend bool operator>(const TimePeriod&, const TimePeriod&);
	friend bool operator>=(const TimePeriod&, const TimePeriod&);
	friend bool operator<(const TimePeriod&, const TimePeriod&);
	friend bool operator<=(const TimePeriod&, const TimePeriod&);

	friend std::ostream& operator<<(std::ostream&, const TimePeriod&);
	friend std::istream& operator>>(std::istream&, TimePeriod&);
};