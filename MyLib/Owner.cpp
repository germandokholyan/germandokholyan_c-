#include "Owner.h"
#include <sstream>
Owner::Owner(const std::string& name, const std::string& passport)
    : fullName(name), passportNumber(passport) {}
std::string Owner::getFullName() const {
    return fullName;
}
std::string Owner::getPassportNumber() const {
    return passportNumber;
}
void Owner::addVehicle(const std::shared_ptr<Vehicle>& vehicle) {
    ownedVehicles.push_back(vehicle);
}
std::vector<std::shared_ptr<Vehicle>> Owner::getOwnedVehicles() const {
    return ownedVehicles;
}
std::string Owner::getInfo() const {
    std::ostringstream oss;
    oss << "ФИО владельца: " << fullName
        << ", Паспорт: " << passportNumber
        << ", Количество автомобилей: " << ownedVehicles.size();
    return oss.str();
}
