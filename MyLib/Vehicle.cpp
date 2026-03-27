#include "Vehicle.h"
#include "Owner.h"

namespace miit::gai {

    Vehicle::Vehicle(const std::string& regNum,
                     const std::string& make,
                     const std::string& model,
                     const std::string& color,
                     const std::string& engineNum)
        : registrationNumber(regNum),
          make(make),
          model(model),
          color(color),
          engineNumber(engineNum),
          isStolen(false) {}

    std::string Vehicle::getRegistrationNumber() const {
        return registrationNumber;
    }

    std::string Vehicle::getMake() const {
        return make;
    }

    std::string Vehicle::getModel() const {
        return model;
    }

    std::string Vehicle::getColor() const {
        return color;
    }

    std::string Vehicle::getEngineNumber() const {
        return engineNumber;
    }

    std::string Vehicle::getInfo() const {
        std::string info = "Авто [" + registrationNumber + "] " + make + " " + model
                           + ", цвет: " + color + ", двигатель: " + engineNumber
                           + ", угнан: " + (isStolen ? "да" : "нет") + "\n";

        if (currentOwner) {
            info += "Текущий владелец: " + currentOwner->getFullName() + "\n";
        }

        if (!previousOwners.empty()) {
            info += "Предыдущие владельцы:\n";
            for (const auto& owner : previousOwners) {
                info += "  - " + owner->getFullName() + "\n";
            }
        }

        return info;
    }

    void Vehicle::setCurrentOwner(std::shared_ptr<Owner> owner) {
        currentOwner = owner;
    }

    void Vehicle::addPreviousOwner(std::shared_ptr<Owner> owner) {
        previousOwners.push_back(owner);
    }

    bool Vehicle::getIsStolen() const {
        return isStolen;
    }

    void Vehicle::setIsStolen(bool stolen) {
        isStolen = stolen;
    }

} // namespace miit::gai
