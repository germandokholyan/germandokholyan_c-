#include "Car.h"
#include <sstream>
namespace miit::gai {
    Car::Car(const std::string& reg, const std::string& eng, const std::string& br,
             const std::string& mod, const std::string& col, bool stolen)
        : regNumber(reg), engineNumber(eng), brand(br), model(mod), color(col), isStolen(stolen) {}
    std::string Car::toString() const {
        std::ostringstream oss;
        oss << "Авто [" << regNumber << "] " << brand << " " << model
            << ", цвет: " << color << ", угнан: " << (isStolen ? "да" : "нет");
        return oss.str();
    }
} // namespace miit::gai
