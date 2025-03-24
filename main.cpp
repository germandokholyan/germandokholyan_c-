#include <iostream>
#include "Person.h"

int main()
{
    setlocale(LC_ALL, "russian");
    std::string firstName;
    std::string lastName;
    std::string patronymic;

    std::cout << "Введите фамилию: ";
    std::cin >> lastName;

    std::cout << "Введите имя: ";
    std::cin >> firstName;

    std::cout << "Введите отчество: ";
    std::cin >> patronymic;
    setlocale(LC_ALL, "russian");
    Person person(lastName, firstName, patronymic);
    person.Show();
    person.ShowFormal();

    return 0;
}
