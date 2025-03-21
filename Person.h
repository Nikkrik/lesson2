#pragma once
#include "MyDateTime.h"
class Person
{
private:
	char name[20];
	char surname[20];
	char patronymic[20];
	MyDateTime date;
	int age;
	int pay;

public:
	Person();
	Person(const char* name, const char* surname, const char* patronymic, MyDateTime date, int age, int pay);
	~Person();
	Person(const Person& other);

	
	Person& operator=(Person& other);
	bool operator>=(const Person& other);
	bool operator==(const Person& other);
	bool operator<=(const Person& other);
	bool operator!=(const Person& other);
	bool operator>(const Person& other);
	bool operator<(const Person& other);

	friend std::istream& operator>>(std::istream& is, Person& other);
	friend std::ostream& operator<<(std::ostream& os, const Person& other);
};

