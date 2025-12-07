#include "Vehicle.h"
#include <sstream>
Vehicle::Vehicle(const std::string& regNum, const std::string& make, const std::string& model, const std::string& color, const std::string& engineNum)
    : registrationNumber(regNum), make(make), model(model), color(color), engineNumber(engineNum) {}
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
    std::ostringstream oss;
    oss << "Регистрационный номер: " << registrationNumber
        << ", Марка: " << make
        << ", Модель: " << model
        << ", Цвет: " << color
        << ", Номер двигателя: " << engineNumber;
    return oss.str();
}
