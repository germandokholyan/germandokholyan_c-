#include "Garage.h"
#include <algorithm>
#include <map>

namespace miit::gai {

    void Garage::addCar(std::shared_ptr<Car> car) {
        cars.push_back(car);
    }

    const std::vector<std::shared_ptr<Car>>& Garage::getCars() const {
        return cars;
    }

    std::shared_ptr<Car> Garage::findCarByRegNumber(const std::string& reg) const {
        for (const auto& car : cars) {
            if (car->getRegNumber() == reg) {
                return car;
            }
        }
        return nullptr;
    }

    std::shared_ptr<Owner> Garage::findOwnerByRegNumber(const std::string& reg) const {
        auto car = findCarByRegNumber(reg);
        if (car) {
            return car->getCurrentOwner();
        }
        return nullptr;
    }

    std::shared_ptr<Car> Garage::findCarByEngineNumber(const std::string& eng) const {
        for (const auto& car : cars) {
            if (car->getEngineNumber() == eng) {
                return car;
            }
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Car>> Garage::getStolenCars() const {
        std::vector<std::shared_ptr<Car>> result;
        for (const auto& car : cars) {
            if (car->getIsStolen()) {
                result.push_back(car);
            }
        }
        return result;
    }

    std::vector<std::shared_ptr<Car>> Garage::getCarsInAccidentPeriod(const std::string& startDate, const std::string& endDate) const {
        std::vector<std::shared_ptr<Car>> result;
        for (const auto& car : cars) {
            for (const auto& accident : car->getAccidents()) {
                if (accident->getDate() >= startDate && accident->getDate() <= endDate) {
                    result.push_back(car);
                    break; // Достаточно одного совпадения
                }
            }
        }
        return result;
    }

    std::vector<std::pair<std::string, int>> Garage::getMostStolenBrands() const {
        std::map<std::string, int> brandCount;
        for (const auto& car : cars) {
            if (car->getIsStolen()) {
                brandCount[car->getBrand()]++;
            }
        }

        std::vector<std::pair<std::string, int>> result(brandCount.begin(), brandCount.end());
        std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        return result;
    }

    void Garage::displayAllCars() const {
        for (const auto& car : cars) {
            car->displayInfo();
            std::cout << "------------------------" << std::endl;
        }
    }

}
