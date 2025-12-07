#include "GAIManager.h"
#include <algorithm>
#include <unordered_map>

void GAIManager::addVehicle(const std::shared_ptr<Vehicle>& vehicle) {
    vehicles.push_back(vehicle);
}

void GAIManager::addOwner(const std::shared_ptr<Owner>& owner) {
    owners.push_back(owner);
}

void GAIManager::addRegistrationRecord(const std::shared_ptr<RegistrationRecord>& record) {
    records.push_back(record);
}

void GAIManager::addStolenVehicle(const std::shared_ptr<StolenVehicle>& stolenVehicle) {
    stolenVehicles.push_back(stolenVehicle);
}

std::shared_ptr<Vehicle> GAIManager::getVehicleByRegistrationNumber(const std::string& regNum) const {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getRegistrationNumber() == regNum) {
            return vehicle;
        }
    }
    return nullptr;
}

std::shared_ptr<Owner> GAIManager::getOwnerByVehicleRegistrationNumber(const std::string& regNum) const {
    for (const auto& record : records) {
        if (record->getVehicle()->getRegistrationNumber() == regNum) {
            return record->getOwner();
        }
    }
    return nullptr;
}

std::shared_ptr<Vehicle> GAIManager::getVehicleByEngineNumber(const std::string& engineNum) const {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getEngineNumber() == engineNum) {
            return vehicle;
        }
    }
    return nullptr;
}

std::shared_ptr<RegistrationRecord> GAIManager::getRegistrationRecordByEngineNumber(const std::string& engineNum) const {
    for (const auto& record : records) {
        if (record->getVehicle()->getEngineNumber() == engineNum) {
            return record;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<StolenVehicle>> GAIManager::getAllStolenVehicles() const {
    return stolenVehicles;
}
std::vector<std::shared_ptr<RegistrationRecord>> GAIManager::getVehiclesWithAccidentsInPeriod(const std::string& startDate, const std::string& endDate) const {
    std::vector<std::shared_ptr<RegistrationRecord>> result;
    for (const auto& record : records) {
        // Простая проверка: если история аварий содержит дату в указанном диапазоне.
        // В реальности потребуется более сложная логика парсинга дат.
        if (!record->getAccidentHistory().empty()) {
            // Здесь можно добавить логику для фильтрации по дате, если бы мы хранили даты аварий отдельно.
            result.push_back(record);
        }
    }
    return result;
}
std::vector<std::pair<std::string, int>> GAIManager::getMostStolenMakes() const {
    std::unordered_map<std::string, int> makeCount;
    for (const auto& stolenVehicle : stolenVehicles) {
        std::string make = stolenVehicle->getMake();
        makeCount[make]++;
    }

    // Преобразование в вектор пар и сортировка по убыванию
    std::vector<std::pair<std::string, int>> sortedMakes(makeCount.begin(), makeCount.end());
    std::sort(sortedMakes.begin(), sortedMakes.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    return sortedMakes;
}
