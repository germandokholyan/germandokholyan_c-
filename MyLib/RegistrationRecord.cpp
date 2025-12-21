#include "RegistrationRecord.h"
#include "Vehicle.h"
#include "Owner.h"

namespace miit::gai {
    RegistrationRecord::RegistrationRecord(const std::shared_ptr<Vehicle>& veh,
                                         const std::shared_ptr<Owner>& own,
                                         const std::string& date)
        : vehicle(veh), owner(own), registrationDate(date) {}

    std::shared_ptr<Vehicle> RegistrationRecord::getVehicle() const {
        return vehicle;
    }
    std::shared_ptr<Owner> RegistrationRecord::getOwner() const {
        return owner;
    }

    std::string RegistrationRecord::getRegistrationDate() const {
        return registrationDate;
    }

    std::vector<std::string> RegistrationRecord::getPreviousOwners() const {
        return previousOwners;
    }

    std::vector<std::string> RegistrationRecord::getAccidentHistory() const {
        return accidentHistory;
    }

    void RegistrationRecord::addPreviousOwner(const std::string& ownerName) {
        previousOwners.push_back(ownerName);
    }

    void RegistrationRecord::addAccident(const std::string& accidentDetails) {
        accidentHistory.push_back(accidentDetails);
    }

    std::string RegistrationRecord::getInfo() const {
        std::string info = "Регистрация: " + registrationDate + "\n";
        info += "Автомобиль: " + vehicle->getBrand() + " " + vehicle->getModel() + "\n";
        info += "Владелец: " + owner->getFullName() + "\n";

        if (!previousOwners.empty()) {
            info += "Предыдущие владельцы:\n";
            for (const auto& name : previousOwners) {
                info += "  - " + name + "\n";
            }
        }

        if (!accidentHistory.empty()) {
            info += "Аварии:\n";
            for (const auto& details : accidentHistory) {
                info += "  - " + details + "\n";
            }
        }

        return info;
    }

} // namespace miit::gai
