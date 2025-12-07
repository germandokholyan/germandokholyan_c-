#pragma once
#include <vector>
#include <memory>
#include "Car.h"

namespace miit::gai {

    class Garage {
    private:
        std::vector<std::shared_ptr<Car>> cars;

    public:
        void addCar(std::shared_ptr<Car> car);
        const std::vector<std::shared_ptr<Car>>& getCars() const;

        // Задание 1: найти авто по рег. номеру
        std::shared_ptr<Car> findCarByRegNumber(const std::string& reg) const;

        // Задание 2: найти владельца по рег. номеру
        std::shared_ptr<Owner> findOwnerByRegNumber(const std::string& reg) const;

        // Задание 3: найти авто по номеру двигателя
        std::shared_ptr<Car> findCarByEngineNumber(const std::string& eng) const;

        // Задание 4: получить список угнанных авто
        std::vector<std::shared_ptr<Car>> getStolenCars() const;

        // Задание 5: получить список авто, попавших в аварию в период
        std::vector<std::shared_ptr<Car>> getCarsInAccidentPeriod(const std::string& startDate, const std::string& endDate) const;

        // Задание 6: получить список наиболее угоняемых марок
        std::vector<std::pair<std::string, int>> getMostStolenBrands() const;

        void displayAllCars() const;
    };

} 
