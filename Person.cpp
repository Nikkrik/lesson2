#include "Person.h"

Person::Person()
{
	strcpy_s(name, sizeof(char) * 20, " ");
	strcpy_s(surname, sizeof(char) * 20, " ");
	strcpy_s(patronymic, sizeof(char) * 20, " ");
	date = MyDateTime();
	age = 0;
	pay = 0;

}

Person::Person(const char* name, const char* surname, const char* patronymic, MyDateTime date, int age, int pay)
{
	strcpy_s(this->name, sizeof(char) * 20, name);
	strcpy_s(this->surname, sizeof(char) * 20, surname);
	strcpy_s(this->patronymic, sizeof(char) * 20, patronymic);
	this->date = date;
	this->age = age;
	this->pay = pay;
}

Person::~Person()
{

}

Person::Person(const Person& other)
{
	strcpy_s(name, sizeof(char) * 20, other.name);
	strcpy_s(surname, sizeof(char) * 20, other.surname);
	strcpy_s(patronymic, sizeof(char) * 20, other.patronymic);
	date = other.date;
	age = other.age;
	pay = other.pay;
}



Person& Person::operator=(Person& other)
{
	strcpy_s(name, sizeof(char) * 20, other.name);
	strcpy_s(surname, sizeof(char) * 20, other.surname);
	strcpy_s(patronymic, sizeof(char) * 20, other.patronymic);
	date = other.date;
	age = other.age;
	pay = other.pay;

	return *this;
}



bool Person::operator>=(const Person& other)
{
	return date >= other.date;
}

bool Person::operator==(const Person& other)
{
	return date == other.date;

}

bool Person::operator<=(const Person& other)
{
	return date <= other.date;
}

bool Person::operator!=(const Person& other)
{
	return date != other.date;
}

bool Person::operator>(const Person& other)
{
	return date > other.date;
}

bool Person::operator<(const Person& other)
{
	return date < other.date;
}



std::ostream& operator<<(std::ostream& os, const Person& other)
{
	os << other.name << "/" << other.surname << "/" << other.patronymic << "/" << other.date << "/" << other.age << "/" << other.pay << std::endl;
	return os;
}
