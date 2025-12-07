#include "StolenVehicle.h"
#include <sstream>
StolenVehicle::StolenVehicle(const std::string& regNum, const std::string& make, const std::string& model, const std::string& color, const std::string& engineNum,
                             const std::string& theftDate, const std::string& reportNum)
    : Vehicle(regNum, make, model, color, engineNum), theftDate(theftDate), reportNumber(reportNum) {}
std::string StolenVehicle::getTheftDate() const {
    return theftDate;
}
std::string StolenVehicle::getReportNumber() const {
    return reportNumber;
}
std::string StolenVehicle::getInfo() const {
    std::ostringstream oss;
    oss << Vehicle::getInfo()
        << ", Статус: Украден\n"
        << "Дата кражи: " << theftDate
        << ", Номер заявления: " << reportNumber;
    return oss.str();
}
