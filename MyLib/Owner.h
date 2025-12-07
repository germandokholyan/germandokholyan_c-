#pragma once
#include <string>
#include <vector>
#include <memory>
class Vehicle; 
class Owner {
private:
    std::string fullName;
    std::string passportNumber;
    std::vector<std::shared_ptr<Vehicle>> ownedVehicles;
public:
    Owner(const std::string& name, const std::string& passport);
    // Getters
    std::string getFullName() const;
    std::string getPassportNumber() const;
    // Методы для управления автомобилями
    void addVehicle(const std::shared_ptr<Vehicle>& vehicle);
    std::vector<std::shared_ptr<Vehicle>> getOwnedVehicles() const;
    // Метод для вывода информации
    std::string getInfo() const;
};
