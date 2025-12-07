#include "Car.h"
#include <iostream>
namespace miit::gai {
    Owner::Owner(const std::string& name, const std::string& addr)
        : fullName(name), address(addr) {}
    std::string Owner::getFullName() const { return fullName; }
    std::string Owner::getAddress() const { return address; }
    void Owner::displayInfo() const {
        std::cout << "Владелец: " << fullName << ", Адрес: " << address << std::endl;
    }
    Accident::Accident(const std::string& d, const std::string& desc)
        : date(d), description(desc) {}

    std::string Accident::getDate() const { return date; }
    std::string Accident::getDescription() const { return description; }

    void Accident::displayInfo() const {
        std::cout << "Авария: " << date << " - " << description << std::endl;
    }

    Car::Car(const std::string& reg, const std::string& eng, const std::string& br,
             const std::string& mod, const std::string& col, bool stolen)
        : regNumber(reg), engineNumber(eng), brand(br), model(mod), color(col), isStolen(stolen) {}

    std::string Car::getRegNumber() const { return regNumber; }
    std::string Car::getEngineNumber() const { return engineNumber; }
    std::string Car::getBrand() const { return brand; }
    std::string Car::getModel() const { return model; }
    std::string Car::getColor() const { return color; }
    bool Car::getIsStolen() const { return isStolen; }
    std::shared_ptr<Owner> Car::getCurrentOwner() const { return currentOwner; }
    const std::vector<std::shared_ptr<Owner>>& Car::getPreviousOwners() const { return previousOwners; }
    const std::vector<std::shared_ptr<Accident>>& Car::getAccidents() const { return accidents; }

    void Car::setCurrentOwner(std::shared_ptr<Owner> owner) { currentOwner = owner; }
    void Car::addPreviousOwner(std::shared_ptr<Owner> owner) { previousOwners.push_back(owner); }
    void Car::addAccident(std::shared_ptr<Accident> accident) { accidents.push_back(accident); }

    void Car::displayInfo() const {
        std::cout << "Авто [" << regNumber << "] " << brand << " " << model
                  << ", цвет: " << color << ", угнан: " << (isStolen ? "да" : "нет") << std::endl;
        if (currentOwner) {
            std::cout << "Текущий владелец: ";
            currentOwner->displayInfo();
        }
        if (!previousOwners.empty()) {
            std::cout << "Предыдущие владельцы:" << std::endl;
            for (const auto& owner : previousOwners) {
                owner->displayInfo();
            }
        }
        if (!accidents.empty()) {
            std::cout << "Аварии:" << std::endl;
            for (const auto& accident : accidents) {
                accident->displayInfo();
            }
        }
    }

}
