#pragma once
#include "Vehicle.h"
class StolenVehicle : public Vehicle {
private:
    std::string theftDate;
    std::string reportNumber;
public:
    StolenVehicle(const std::string& regNum, const std::string& make, const std::string& model, const std::string& color, const std::string& engineNum,
                  const std::string& theftDate, const std::string& reportNum);
    std::string getTheftDate() const;
    std::string getReportNumber() const;
    // Переопределенный метод для вывода информации
    std::string getInfo() const override;
};
