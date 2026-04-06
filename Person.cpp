#include <iostream>
#include "Person.h"

Person::Person()
{
	lastName = "";
	firstName = "";
	patronymic = "";
}

Person::Person(const string& ln, const string& fn, const string& pn)
{
	lastName = ln;
	firstName = pn;
	patronymic = pn;
}

void Person::Show()
{
	std::cout << lastName << "" << firstName << endl;
}

void Person::ShowFormal()
{
	std::cout << lastName << "" << firstName << "" << patronymic << endl;
}
