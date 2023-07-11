#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

Date::Date(int year, int month, int day)
{
	
	if ((month > 0 && month < 13) && (day > 0 && day <= Date::GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" <<endl;
	}
}

int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}

}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		//进位
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
		
	return *this;
}

Date Date::operator+(int day)
{
	Date ret = *this;
	ret += day;
	
	return ret;
}



void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator==(const Date& d2)
{
	return _year == d2._year
		&& _month == d2._month
		&& _day == d2._day;
}

bool Date::operator<(const Date& d2)
{
	if (_year > d2._year)
		return false;
	else if (_year == d2._year && _month > d2._month)
		return false;
	else if (_year == d2._year && _month == d2._month && _day > d2._day)
		return false;
	else
		return true;
}

bool Date::operator>(const Date& d2)
{
	return !(*this < d2 && *this == d2);
}

bool Date::operator!=(const Date& d2)
{
	return !(*this == d2);
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	return *this;
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

