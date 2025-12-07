#pragma once
#include <vector>
#include <memory>
#include <string>
class Vehicle;
class Owner;
class RegistrationRecord;
class StolenVehicle;
class GAIManager {
private:
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    std::vector<std::shared_ptr<Owner>> owners;
    std::vector<std::shared_ptr<RegistrationRecord>> records;
    std::vector<std::shared_ptr<StolenVehicle>> stolenVehicles;
public:
    // Методы для добавления данных
    void addVehicle(const std::shared_ptr<Vehicle>& vehicle);
    void addOwner(const std::shared_ptr<Owner>& owner);
    void addRegistrationRecord(const std::shared_ptr<RegistrationRecord>& record);
    void addStolenVehicle(const std::shared_ptr<StolenVehicle>& stolenVehicle);
    // Задание 1: Выдавать информацию об автомобиле по его регистрационному знаку
    std::shared_ptr<Vehicle> getVehicleByRegistrationNumber(const std::string& regNum) const;
    // Задание 2: Выдавать информацию об автовладельце по регистрационному знаку данного автомобиля
    std::shared_ptr<Owner> getOwnerByVehicleRegistrationNumber(const std::string& regNum) const;
    // Задание 3: Выдавать информацию об автомобиле по номеру двигателя
    std::shared_ptr<Vehicle> getVehicleByEngineNumber(const std::string& engineNum) const;
    std::shared_ptr<RegistrationRecord> getRegistrationRecordByEngineNumber(const std::string& engineNum) const;
    // Задание 4: Выдавать список угнанных автомобилей
    std::vector<std::shared_ptr<StolenVehicle>> getAllStolenVehicles() const;
    // Задание 5: Выдавать список автомобилей, попавших в аварию в данный период времени
    std::vector<std::shared_ptr<RegistrationRecord>> getVehiclesWithAccidentsInPeriod(const std::string& startDate, const std::string& endDate) const;
    // Задание 6: Выдавать список наиболее угоняемых автомобилей по марке
    std::vector<std::pair<std::string, int>> getMostStolenMakes() const;
};
