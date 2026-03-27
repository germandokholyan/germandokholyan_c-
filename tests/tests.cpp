#include <gtest/gtest.h>
#include <memory>
#include "Vehicle.h"
#include "Owner.h"
#include "RegistrationRecord.h"
#include "StolenVehicle.h"
#include "GAIManager.h"
// Тестирование класса Vehicle
TEST(VehicleTest, ConstructorAndGetters) {
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");

    EXPECT_EQ(vehicle->getRegistrationNumber(), "А123ББ77");
    EXPECT_EQ(vehicle->getMake(), "Toyota");
    EXPECT_EQ(vehicle->getModel(), "Camry");
    EXPECT_EQ(vehicle->getColor(), "Серебристый");
    EXPECT_EQ(vehicle->getEngineNumber(), "ENG123456");
}
TEST(VehicleTest, GetInfo) {
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    std::string info = vehicle->getInfo();
    EXPECT_NE(info.find("Регистрационный номер: А123ББ77"), std::string::npos);
    EXPECT_NE(info.find("Марка: Toyota"), std::string::npos);
    EXPECT_NE(info.find("Модель: Camry"), std::string::npos);
    EXPECT_NE(info.find("Цвет: Серебристый"), std::string::npos);
    EXPECT_NE(info.find("Номер двигателя: ENG123456"), std::string::npos);
}
// Тестирование класса Owner
TEST(OwnerTest, ConstructorAndGetters) {
    auto owner = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");

    EXPECT_EQ(owner->getFullName(), "Иванов Иван Иванович");
    EXPECT_EQ(owner->getPassportNumber(), "1234 567890");
    EXPECT_EQ(owner->getOwnedVehicles().size(), 0);
}
TEST(OwnerTest, AddVehicle) {
    auto owner = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    owner->addVehicle(vehicle);
    auto vehicles = owner->getOwnedVehicles();
    ASSERT_EQ(vehicles.size(), 1);
    EXPECT_EQ(vehicles[0]->getRegistrationNumber(), "А123ББ77");
}
TEST(OwnerTest, GetInfo) {
    auto owner = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    owner->addVehicle(vehicle);
    std::string info = owner->getInfo();
    EXPECT_NE(info.find("ФИО владельца: Иванов Иван Иванович"), std::string::npos);
    EXPECT_NE(info.find("Паспорт: 1234 567890"), std::string::npos);
    EXPECT_NE(info.find("Количество автомобилей: 1"), std::string::npos);
}
// Тестирование класса RegistrationRecord
TEST(RegistrationRecordTest, ConstructorAndGetters) {
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    auto owner = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");
    auto record = std::make_shared<RegistrationRecord>(vehicle, owner, "2023-01-15");
    EXPECT_EQ(record->getVehicle()->getRegistrationNumber(), "А123ББ77");
    EXPECT_EQ(record->getOwner()->getFullName(), "Иванов Иван Иванович");
    EXPECT_EQ(record->getRegistrationDate(), "2023-01-15");
    EXPECT_TRUE(record->getPreviousOwners().empty());
    EXPECT_TRUE(record->getAccidentHistory().empty());
}
TEST(RegistrationRecordTest, AddPreviousOwnerAndAccident) {
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    auto owner = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");
    auto record = std::make_shared<RegistrationRecord>(vehicle, owner, "2023-01-15");
    record->addPreviousOwner("Петров Петр Петрович");
    record->addPreviousOwner("Сидоров Сидор Сидорович");
    record->addAccident("ДТП 2023-05-20");
    record->addAccident("ДТП 2023-06-15");
    EXPECT_EQ(record->getPreviousOwners(), "Петров Петр Петрович, Сидоров Сидор Сидорович");
    EXPECT_EQ(record->getAccidentHistory(), "ДТП 2023-05-20; ДТП 2023-06-15");
}
TEST(RegistrationRecordTest, GetInfo) {
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    auto owner = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");
    auto record = std::make_shared<RegistrationRecord>(vehicle, owner, "2023-01-15");
    record->addPreviousOwner("Петров Петр Петрович");
    record->addAccident("ДТП 2023-05-20");
    std::string info = record->getInfo();
    EXPECT_NE(info.find("Запись регистрации:"), std::string::npos);
    EXPECT_NE(info.find("Дата регистрации: 2023-01-15"), std::string::npos);
    EXPECT_NE(info.find("Автомобиль: Регистрационный номер: А123ББ77"), std::string::npos);
    EXPECT_NE(info.find("Владелец: ФИО владельца: Иванов Иван Иванович"), std::string::npos);
    EXPECT_NE(info.find("Предыдущие владельцы: Петров Петр Петрович, Сидоров Сидор Сидорович"), std::string::npos);
    EXPECT_NE(info.find("История аварий: ДТП 2023-05-20"), std::string::npos);
}
// Тестирование класса StolenVehicle
TEST(StolenVehicleTest, ConstructorAndGetters) {
    auto stolenVehicle = std::make_shared<StolenVehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456", "2023-07-01", "Заявление №123");
    EXPECT_EQ(stolenVehicle->getRegistrationNumber(), "А123ББ77");
    EXPECT_EQ(stolenVehicle->getMake(), "Toyota");
    EXPECT_EQ(stolenVehicle->getModel(), "Camry");
    EXPECT_EQ(stolenVehicle->getColor(), "Серебристый");
    EXPECT_EQ(stolenVehicle->getEngineNumber(), "ENG123456");
    EXPECT_EQ(stolenVehicle->getTheftDate(), "2023-07-01");
    EXPECT_EQ(stolenVehicle->getReportNumber(), "Заявление №123");
}
TEST(StolenVehicleTest, GetInfo) {
    auto stolenVehicle = std::make_shared<StolenVehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456", "2023-07-01", "Заявление №123");
    std::string info = stolenVehicle->getInfo();
    EXPECT_NE(info.find("Регистрационный номер: А123ББ77"), std::string::npos);
    EXPECT_NE(info.find("Статус: Украден"), std::string::npos);
    EXPECT_NE(info.find("Дата кражи: 2023-07-01"), std::string::npos);
    EXPECT_NE(info.find("Номер заявления: Заявление №123"), std::string::npos);
}
// Тестирование класса GAIManager
TEST(GAIManagerTest, AddAndGetVehicleByRegistrationNumber) {
    GAIManager gaiManager;
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    gaiManager.addVehicle(vehicle);

    auto foundVehicle = gaiManager.getVehicleByRegistrationNumber("А123ББ77");
    ASSERT_NE(foundVehicle, nullptr);
    EXPECT_EQ(foundVehicle->getRegistrationNumber(), "А123ББ77");
}
TEST(GAIManagerTest, AddAndGetOwnerByVehicleRegistrationNumber) {
    GAIManager gaiManager;
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    auto owner = std::make_shared<Owner>("Иванов Иван Иванович", "1234 567890");
    auto record = std::make_shared<RegistrationRecord>(vehicle, owner, "2023-01-15");
    gaiManager.addVehicle(vehicle);
    gaiManager.addOwner(owner);
    gaiManager.addRegistrationRecord(record);

    auto foundOwner = gaiManager.getOwnerByVehicleRegistrationNumber("А123ББ77");
    ASSERT_NE(foundOwner, nullptr);
    EXPECT_EQ(foundOwner->getFullName(), "Иванов Иван Иванович");
}
TEST(GAIManagerTest, AddAndGetVehicleByEngineNumber) {
    GAIManager gaiManager;
    auto vehicle = std::make_shared<Vehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456");
    gaiManager.addVehicle(vehicle);

    auto foundVehicle = gaiManager.getVehicleByEngineNumber("ENG123456");
    ASSERT_NE(foundVehicle, nullptr);
    EXPECT_EQ(foundVehicle->getEngineNumber(), "ENG123456");
}
TEST(GAIManagerTest, GetAllStolenVehicles) {
    GAIManager gaiManager;
    auto stolenVehicle1 = std::make_shared<StolenVehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456", "2023-07-01", "Заявление №123");
    auto stolenVehicle2 = std::make_shared<StolenVehicle>("В456СС77", "BMW", "X5", "Черный", "ENG789012", "2023-07-05", "Заявление №456");
    gaiManager.addStolenVehicle(stolenVehicle1);
    gaiManager.addStolenVehicle(stolenVehicle2);

    auto stolenList = gaiManager.getAllStolenVehicles();
    ASSERT_EQ(stolenList.size(), 2);
    EXPECT_EQ(stolenList[0]->getRegistrationNumber(), "А123ББ77");
    EXPECT_EQ(stolenList[1]->getRegistrationNumber(), "В456СС77");
}
TEST(GAIManagerTest, GetMostStolenMakes) {
    GAIManager gaiManager;
    auto stolenVehicle1 = std::make_shared<StolenVehicle>("А123ББ77", "Toyota", "Camry", "Серебристый", "ENG123456", "2023-07-01", "Заявление №123");
    auto stolenVehicle2 = std::make_shared<StolenVehicle>("В456СС77", "BMW", "X5", "Черный", "ENG789012", "2023-07-05", "Заявление №456");
    auto stolenVehicle3 = std::make_shared<StolenVehicle>("Г789ДД77", "Toyota", "Corolla", "Красный", "ENG345678", "2023-07-10", "Заявление №789");
    gaiManager.addStolenVehicle(stolenVehicle1);
    gaiManager.addStolenVehicle(stolenVehicle2);
    gaiManager.addStolenVehicle(stolenVehicle3);
    auto mostStolen = gaiManager.getMostStolenMakes();
    ASSERT_EQ(mostStolen.size(), 2);
    EXPECT_EQ(mostStolen[0].first, "Toyota"); // Toyota должна быть первой, так как у нее 2 угона
    EXPECT_EQ(mostStolen[0].second, 2);
    EXPECT_EQ(mostStolen[1].first, "BMW");
    EXPECT_EQ(mostStolen[1].second, 1);
}
// Главная функция для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
