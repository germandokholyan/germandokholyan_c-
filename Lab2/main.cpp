#include <iostream>
#include <memory>
#include "GAIManager.h"
#include "Vehicle.h"
#include "Owner.h"
#include "RegistrationRecord.h"
#include "StolenVehicle.h"

int main() {
    GAIManager gaiManager;
    // Создаем несколько объектов для демонстрации
    auto vehicle1 = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    auto vehicle2 = std::make_shared<Vehicle>("В456СС77", "BMW", "X5", "Черный", "ENG789012");
    auto owner1 = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");
    auto owner2 = std::make_shared<Owner>("Петров Петр Петрович", "0987 654321");
    auto record1 = std::make_shared<RegistrationRecord>(vehicle1, owner1, "2023-01-15");
    record1->addPreviousOwner("Сидоров Сидор Сидорович");
    record1->addAccident("ДТП 2023-05-20");
    auto record2 = std::make_shared<RegistrationRecord>(vehicle2, owner2, "2023-02-10");
    record2->addAccident("ДТП 2023-06-15");
    auto stolenVehicle1 = std::make_shared<StolenVehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456", "2023-07-01", "Заявление №123");
    auto stolenVehicle2 = std::make_shared<StolenVehicle>("В456СС77", "BMW", "X5", "Черный", "ENG789012", "2023-07-05", "Заявление №456");
    // Добавляем объекты в систему
    gaiManager.addVehicle(vehicle1);
    gaiManager.addVehicle(vehicle2);
    gaiManager.addOwner(owner1);
    gaiManager.addOwner(owner2);
    gaiManager.addRegistrationRecord(record1);
    gaiManager.addRegistrationRecord(record2);
    gaiManager.addStolenVehicle(stolenVehicle1);
    gaiManager.addStolenVehicle(stolenVehicle2);
    // Демонстрация выполнения заданий=
    std::cout << "=== Задание 1: Информация об автомобиле по регистрационному знаку ===" << std::endl;
    auto foundVehicle = gaiManager.getVehicleByRegistrationNumber("А123ББ77");
    if (foundVehicle) {
        std::cout << foundVehicle->getInfo() << std::endl;
    } else {
        std::cout << "Автомобиль не найден." << std::endl;
    }
    std::cout << "\n=== Задание 2: Информация об автовладельце по регистрационному знаку ===" << std::endl;
    auto foundOwner = gaiManager.getOwnerByVehicleRegistrationNumber("А123ББ77");
    if (foundOwner) {
        std::cout << foundOwner->getInfo() << std::endl;
    } else {
        std::cout << "Владелец не найден." << std::endl;
    }
    std::cout << "\n=== Задание 3: Информация об автомобиле по номеру двигателя ===" << std::endl;
    auto foundVehicleByEngine = gaiManager.getVehicleByEngineNumber("ENG123456");
    if (foundVehicleByEngine) {
        std::cout << foundVehicleByEngine->getInfo() << std::endl;
    } else {
        std::cout << "Автомобиль по номеру двигателя не найден." << std::endl;
    }
    std::cout << "\n=== Задание 4: Список угнанных автомобилей ===" << std::endl;
    auto stolenList = gaiManager.getAllStolenVehicles();
    for (const auto& stolen : stolenList) {
        std::cout << stolen->getInfo() << std::endl;
    }
    std::cout << "\n=== Задание 5: Автомобили, попавшие в аварию (упрощенная демонстрация) ===" << std::endl;
    auto accidentRecords = gaiManager.getVehiclesWithAccidentsInPeriod("2023-01-01", "2023-12-31");
    for (const auto& record : accidentRecords) {
        std::cout << record->getInfo() << std::endl;
    }
    std::cout << "\n=== Задание 6: Наиболее угоняемые автомобили по марке ===" << std::endl;
    auto mostStolen = gaiManager.getMostStolenMakes();
    for (const auto& [make, count] : mostStolen) {
        std::cout << "Марка: " << make << ", Количество угонов: " << count << std::endl;
    }
    return 0;
}
