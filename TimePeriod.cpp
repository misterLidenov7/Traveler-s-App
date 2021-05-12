#include "TimePeriod.hpp"

TimePeriod::TimePeriod(): day(1), month(1), year(1999) {}

TimePeriod::TimePeriod(const int day, const int month, const int year){

	this->day = day;
	this->month = month;
	this->year = year;
}

const int TimePeriod::dayGetter() const{
	return this->day;
}

const int TimePeriod::monthGetter() const{
	return this->month;
}

const int TimePeriod::yearGetter() const{
	return this->year;
}

bool TimePeriod::leapYearChecker(int year) const
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
			return true;
	}
	return false;
}

bool TimePeriod::isValid(const int, const int, const int) const
{
	if (year < 1999 || year > 2100) {
		return false;
	}

	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 1 || day > 31) {
			return false;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day < 1 || day > 31) {
			return false;
		}
	}
	if (month < 1 || month > 12) {
		return false;
	}

	if (month == 2 && leapYearChecker(year) == false) {

		if (day < 1 || day > 28) {
			return false;
		}
	}
	else if(month == 2 && leapYearChecker(year) == true){

		if (day < 1 || day > 29) {
			return false;
		}
	}
	return true;
}

bool operator==(const TimePeriod& fst, const TimePeriod& snd)
{
	return fst.dayGetter() == snd.dayGetter() 
		&& fst.monthGetter() == snd.monthGetter()
		&& fst.yearGetter() == snd.yearGetter();
}

bool operator>(const TimePeriod& fst, const TimePeriod& snd)
{
	bool flag = false;

	if (fst.yearGetter() > snd.yearGetter()) {
		flag = true;
	}
	else if (fst.yearGetter() == snd.yearGetter()) {

		if (fst.monthGetter() > snd.monthGetter()) {
			flag = true;
		}
		else if (fst.monthGetter() == snd.monthGetter()) {
			
			if (fst.dayGetter() > snd.dayGetter()) {
				flag = true;
			}
			else {
				flag = false;
			}
		}
		else {
			flag = false;
		}
	}
	else {
		flag = false;
	}
	return flag;
}

bool operator>=(const TimePeriod& fst, const TimePeriod& snd)
{
	return (fst > snd) || (fst == snd);
}

bool operator<(const TimePeriod& fst, const TimePeriod& snd)
{
	bool flag = false;

	if (fst.yearGetter() < snd.yearGetter()) {
		flag = true;
	}
	else if (fst.yearGetter() == snd.yearGetter()) {

		if (fst.monthGetter() < snd.monthGetter()) {
			flag = true;
		}
		else if (fst.monthGetter() == snd.monthGetter()) {

			if (fst.dayGetter() < snd.dayGetter()) {
				flag = true;
			}
			else {
				flag = false;
			}
		}
		else {
			flag = false;
		}
	}
	else {
		flag = false;
	}
	return flag;
}

bool operator<=(const TimePeriod& fst, const TimePeriod& snd)
{
	return (fst < snd) || (fst == snd);
}

std::ostream& operator<<(std::ostream& out, const TimePeriod& date){

	if (date.isValid(date.day, date.month, date.year) == false) {
		out << "Incorect year-month-day";
		exit(1);
	}
	

	out << date.yearGetter() << "-";
	if (date.monthGetter() < 10) {
		out << "0";
	}
	out << date.monthGetter() << "-";

	if (date.dayGetter() < 10) {
		out << "0";
	}
	out << date.dayGetter();

	return out;
}

std::istream& operator>>(std::istream& input, TimePeriod& date)
{
	std::cout << "Enter year : ";
	input >> date.year;

	std::cout << "Enter month : ";
	input >> date.month;

	std::cout << "Enter day : ";
	input >> date.day;

	return input;
}
