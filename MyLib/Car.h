#pragma once
#include <string>
#include <vector>
namespace miit::gai {
    struct Owner {
        std::string fullName;
        std::string address;
    };

    struct Accident {
        std::string date; // формат: "YYYY-MM-DD"
        std::string description;
    };
    class Car {
    public:
        std::string regNumber;     // регистрационный номер
        std::string engineNumber;  // номер двигателя
        std::string brand;         // марка
        std::string model;         // модель
        std::string color;         // цвет
        bool isStolen;             // угнан ли
        Owner currentOwner;
        std::vector<Owner> previousOwners;
        std::vector<Accident> accidents;

        Car() = default;
        Car(const std::string& reg, const std::string& eng, const std::string& br,
            const std::string& mod, const std::string& col, bool stolen = false);

        std::string toString() const;
    };

}
