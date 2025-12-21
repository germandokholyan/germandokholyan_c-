#pragma once
#include <string>
#include <memory>
#include <vector> // Для std::vector

namespace miit::gai {

    class Owner; // Forward declaration

    /**
     * @brief Класс, представляющий автомобиль.
     */
    class Vehicle {
    private:
        std::string registrationNumber;
        std::string make;
        std::string model;
        std::string color;
        std::string engineNumber;
        bool isStolen;
        std::shared_ptr<Owner> currentOwner; // Изменено: добавлен владелец
        std::vector<std::shared_ptr<Owner>> previousOwners; // Изменено: добавлен вектор предыдущих владельцев

    public:
        /**
         * @brief Конструктор.
         * @param regNum Регистрационный номер.
         * @param make Марка.
         * @param model Модель.
         * @param color Цвет.
         * @param engineNum Номер двигателя.
         */
        Vehicle(const std::string& regNum,
                const std::string& make,
                const std::string& model,
                const std::string& color,
                const std::string& engineNum);

        /**
         * @brief Получает регистрационный номер.
         * @return Регистрационный номер.
         */
        std::string getRegistrationNumber() const;

        /**
         * @brief Получает марку.
         * @return Марка.
         */
        std::string getMake() const;

        /**
         * @brief Получает модель.
         * @return Модель.
         */
        std::string getModel() const;

        /**
         * @brief Получает цвет.
         * @return Цвет.
         */
        std::string getColor() const;

        /**
         * @brief Получает номер двигателя.
         * @return Номер двигателя.
         */
        std::string getEngineNumber() const;

        /**
         * @brief Получает информацию об автомобиле.
         * @return Строка с информацией.
         */
        std::string getInfo() const;

        /**
         * @brief Устанавливает текущего владельца.
         * @param owner Указатель на владельца.
         */
        void setCurrentOwner(std::shared_ptr<Owner> owner);

        /**
         * @brief Добавляет предыдущего владельца.
         * @param owner Указатель на владельца.
         */
        void addPreviousOwner(std::shared_ptr<Owner> owner);

        /**
         * @brief Проверяет, угнан ли автомобиль.
         * @return true, если угнан, false иначе.
         */
        bool getIsStolen() const;

        /**
         * @brief Устанавливает флаг угона.
         * @param stolen true, если угнан, false иначе.
         */
        void setIsStolen(bool stolen);
    };

} 
