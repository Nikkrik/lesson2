#pragma once
#include <iostream>
#include <fstream> 

class MyDateTime
{
private:
	int day;
	int month;
	int year;

	int hour;
	int min;
	int sec;

	

public:
	MyDateTime(int day, int month, int year, int hour, int min, int sec);

	MyDateTime();

	~MyDateTime();

	void printInfo();

	MyDateTime(const MyDateTime& anotherTime);
	
	int getday();
	int getyear();
	int getmonth();
	int gethour();
	int getmin();
	int getsec();

	void setday(int newday);
	void setyear(int newyear);
	void setmonth(int newmonth);
	void sethour(int newhour);
	void setmin(int newmin);
	void setsec(int newsec);

	short compareTo(const MyDateTime& second);

	//Операторы
	
	//1 задание
	
	MyDateTime& operator=(const MyDateTime& other);

	void print();

	short compare(int on, int tw);

	//2 задание
	
	bool operator>=(const MyDateTime& other);
	bool operator==(const MyDateTime& other);
	bool operator<=(const MyDateTime& other);
	bool operator!=(const MyDateTime& other);

	bool operator>(const MyDateTime& other);
	bool operator<(const MyDateTime& other);

	//3 задание
	
	//prefix
	MyDateTime& operator++();
	MyDateTime& operator--();

	//postfix
	MyDateTime operator++(int);
	MyDateTime operator--(int);

	//4 задание

	MyDateTime operator+(const MyDateTime& anotherDate);
	MyDateTime operator-(const MyDateTime& anotherDate);

	//1 задание
	friend std::istream& operator>>(std::istream& is, MyDateTime& dt);
	friend std::ostream& operator<<(std::ostream& os, const MyDateTime& dt);








		













};



