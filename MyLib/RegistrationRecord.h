#pragma once
#include <string>
#include <memory>
class Vehicle;
class Owner;
class RegistrationRecord {
private:
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<Owner> owner;
    std::string registrationDate;
    std::string previousOwners; // История предыдущих владельцев
    std::string accidentHistory; // История аварий
public:
    RegistrationRecord(const std::shared_ptr<Vehicle>& veh, const std::shared_ptr<Owner>& own, const std::string& date);
    std::shared_ptr<Vehicle> getVehicle() const;
    std::shared_ptr<Owner> getOwner() const;
    std::string getRegistrationDate() const;
    std::string getPreviousOwners() const;
    std::string getAccidentHistory() const;
    // Методы для обновления истории
    void addPreviousOwner(const std::string& ownerName);
    void addAccident(const std::string& accidentDetails);
    // Метод для вывода информации
    std::string getInfo() const;
};
