#include "MyDateTime.h"

MyDateTime::MyDateTime(int day, int month, int year, int hour, int min, int sec)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

MyDateTime::MyDateTime()
{
	day = 01;
	month = 01;
	year = 1970;
	hour = 0;
	min = 0;
	sec = 0;
}

MyDateTime::~MyDateTime()
{
}

void MyDateTime::printInfo()
{
	printf("День: %d\n", day);
	printf("Месяц: %d\n", month);
	printf("Год: %d\n", year);
	printf("Час: %d\n", hour);
	printf("Минута: %d\n", min);
	printf("Секунда: %d\n", sec);
}

MyDateTime::MyDateTime(const MyDateTime& anotherTime)
{
	day = anotherTime.day;
	month = anotherTime.month;
	year = anotherTime.year;
	hour = anotherTime.hour;
	min = anotherTime.min;
	sec = anotherTime.sec;
}



int MyDateTime::getday()
{
	return day;
}

int MyDateTime::getyear()
{
	return year;
}

int MyDateTime::getmonth()
{
	return month;
}

int MyDateTime::gethour()
{
	return hour;
}

int MyDateTime::getmin()
{
	return min;
}

int MyDateTime::getsec()
{
	return sec;
}

void MyDateTime::setday(int newday)
{
	day = newday;
}

void MyDateTime::setyear(int newyear)
{
	year = newyear;
}

void MyDateTime::setmonth(int newmonth)
{
	month = newmonth;
}

void MyDateTime::sethour(int newhour)
{
	hour = newhour;
}

void MyDateTime::setmin(int newmin)
{
	min = newmin;
}

void MyDateTime::setsec(int newsec)
{
	sec = newsec;
}

short MyDateTime::compareTo(const MyDateTime& second)
{

	if (this->year != second.year) return this->year > second.year ? 1 : -1;
	if (this->month != second.month) return this->month > second.month ? 1 : -1;
	if (this->day != second.day) return this->day > second.day ? 1 : -1;
	if (this->hour != second.hour) return this->hour > second.hour ? 1 : -1;
	if (this->min != second.min) return this->min > second.min ? 1 : -1;
	if (this->sec != second.sec) return this->sec > second.sec ? 1 : -1;

	
	return 0;
}
//1 задание

MyDateTime& MyDateTime::operator=(const MyDateTime& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
	hour = other.hour;
	min = other.min;
	sec = other.sec;

	return *this;
}

void MyDateTime::print()
{
	printf("%02d-%02d-%4d %02d:%02d:%02d\n\n", day, month, year, hour, min, sec);

}

//2 задание

short MyDateTime::compare(int on, int tw)
{
	return on > tw ? 1 : on < tw ? -1 : 0;
}

bool MyDateTime::operator>=(const MyDateTime& other)
{
	return (this->compareTo(other)) >= 0;
}
bool MyDateTime::operator==(const MyDateTime& other)
{
	return (this->compareTo(other)) == 0;
}
bool MyDateTime::operator<=(const MyDateTime& other)
{
	return (this->compareTo(other)) <= 0;
}
bool MyDateTime::operator!=(const MyDateTime& other)
{
	return (this->compareTo(other)) != 0;
}
bool MyDateTime::operator<(const MyDateTime& other)
{
	return (this->compareTo(other)) < 0;
}
bool MyDateTime::operator>(const MyDateTime& other)
{
	return (this->compareTo(other)) > 0;
}

//3 задание

MyDateTime& MyDateTime::operator++()
{
	day++;
	if (day > 30)
	{
		month++;
		day = 1;

	}

	if (month > 12)
	{
		year++;
		month = 1;
	}

	return *this;
}

MyDateTime& MyDateTime::operator--()
{
	day--;
	if (day == 0)
	{
		day = 30;
		month--;
	}

	if (month == 0)
	{
		month = 12;
		year--;
	}

	return *this;
}

MyDateTime MyDateTime::operator++(int)
{
	MyDateTime tmp = MyDateTime(*this);
	this -> operator++();
	return tmp;
}

MyDateTime MyDateTime::operator--(int)
{
	MyDateTime tmp = MyDateTime(*this);
	this -> operator--();
	return tmp;
}


// 4 задание
MyDateTime MyDateTime::operator+(const MyDateTime& anotherDate)
{
	year += anotherDate.year;
	
	day += anotherDate.day;
	if (day += anotherDate.day > 31)
	{
		month++;
		day = day % 31;
	}
	month += anotherDate.month;
	if (month += anotherDate.month > 12)
	{
		year++;
		month = month % 12;
	}
	hour += anotherDate.hour;
	if (hour += anotherDate.hour > 12)
	{
		day++;
		hour = hour % 24;
	}
	min += anotherDate.min;
	if (min += anotherDate.min > 60)
	{
		hour++;
		min = min % 60;
	}
	sec += anotherDate.sec;
	if (sec += anotherDate.sec > 60)
	{
		min++;
		sec = sec % 60;
	}

	return *this;

}

MyDateTime MyDateTime::operator-(const MyDateTime& anotherDate)
{
	return MyDateTime();
}



std::ostream& operator<<(std::ostream& os, const MyDateTime& cl)
{
	os << cl.day << "/" << cl.month << "/" << cl.year << "/" << cl.hour << "/" << cl.min << "/" << cl.sec << std::endl;
	return os;
}




