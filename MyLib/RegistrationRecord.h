#pragma once
#include <string>
#include <memory>
#include <vector> 
namespace miit::gai {
    class Vehicle;
    class Owner;

    /**
     * @brief Класс, представляющий запись о регистрации автомобиля.
     */
    class RegistrationRecord {
    private:
        std::shared_ptr<Vehicle> vehicle;
        std::shared_ptr<Owner> owner;
        std::string registrationDate;
        std::vector<std::string> previousOwners; // Изменено: строка -> вектор строк
        std::vector<std::string> accidentHistory; // Изменено: строка -> вектор строк

    public:
        /**
         * @brief Конструктор.
         * @param veh Указатель на автомобиль.
         * @param own Указатель на владельца.
         * @param date Дата регистрации.
         */
        RegistrationRecord(const std::shared_ptr<Vehicle>& veh,
                           const std::shared_ptr<Owner>& own,
                           const std::string& date);
        /**
         * @brief Получает автомобиль.
         * @return Указатель на автомобиль.
         */
        std::shared_ptr<Vehicle> getVehicle() const;

        /**
         * @brief Получает владельца.
         * @return Указатель на владельца.
         */
        std::shared_ptr<Owner> getOwner() const;

        /**
         * @brief Получает дату регистрации.
         * @return Дата регистрации.
         */
        std::string getRegistrationDate() const;

        /**
         * @brief Получает историю предыдущих владельцев.
         * @return Вектор с именами предыдущих владельцев.
         */
        std::vector<std::string> getPreviousOwners() const;

        /**
         * @brief Получает историю аварий.
         * @return Вектор с описаниями аварий.
         */
        std::vector<std::string> getAccidentHistory() const;

        /**
         * @brief Добавляет предыдущего владельца.
         * @param ownerName Имя предыдущего владельца.
         */
        void addPreviousOwner(const std::string& ownerName);

        /**
         * @brief Добавляет аварию.
         * @param accidentDetails Описание аварии.
         */
        void addAccident(const std::string& accidentDetails);

        /**
         * @brief Возвращает информацию о записи.
         * @return Строка с информацией.
         */
        std::string getInfo() const;
    };

} 
