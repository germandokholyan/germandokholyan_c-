#include "RegistrationRecord.h"
#include <sstream>
RegistrationRecord::RegistrationRecord(const std::shared_ptr<Vehicle>& veh, const std::shared_ptr<Owner>& own, const std::string& date)
    : vehicle(veh), owner(own), registrationDate(date), previousOwners(""), accidentHistory("") {}
std::shared_ptr<Vehicle> RegistrationRecord::getVehicle() const {
    return vehicle;
}
std::shared_ptr<Owner> RegistrationRecord::getOwner() const {
    return owner;
}
std::string RegistrationRecord::getRegistrationDate() const {
    return registrationDate;
}
std::string RegistrationRecord::getPreviousOwners() const {
    return previousOwners;
}
std::string RegistrationRecord::getAccidentHistory() const {
    return accidentHistory;
}
void RegistrationRecord::addPreviousOwner(const std::string& ownerName) {
    if (!previousOwners.empty()) {
        previousOwners += ", ";
    }
    previousOwners += ownerName;
}
void RegistrationRecord::addAccident(const std::string& accidentDetails) {
    if (!accidentHistory.empty()) {
        accidentHistory += "; ";
    }
    accidentHistory += accidentDetails;
}
std::string RegistrationRecord::getInfo() const {
    std::ostringstream oss;
    oss << "Запись регистрации:\n"
        << "Дата регистрации: " << registrationDate << "\n"
        << "Автомобиль: " << vehicle->getInfo() << "\n"
        << "Владелец: " << owner->getInfo() << "\n"
        << "Предыдущие владельцы: " << (previousOwners.empty() ? "Нет" : previousOwners) << "\n"
        << "История аварий: " << (accidentHistory.empty() ? "Нет" : accidentHistory);
    return oss.str();
}
