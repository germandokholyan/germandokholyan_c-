#pragma once
#include <string>
#include <memory>
class Owner; // Forward declaration
class Vehicle {
private:
    std::string registrationNumber;
    std::string make;
    std::string model;
    std::string color;
    std::string engineNumber;
public:
    Vehicle(const std::string& regNum, const std::string& make, const std::string& model, const std::string& color, const std::string& engineNum);
    
    std::string getRegistrationNumber() const;
    std::string getMake() const;
    std::string getModel() const;
    std::string getColor() const;
    std::string getEngineNumber() const;
    std::string getInfo() const;
};
