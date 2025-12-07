#pragma once
#include <string>
#include <vector>
#include <memory>
namespace miit::gai {
    class Owner {
    private:
        std::string fullName;
        std::string address;
    public:
        Owner(const std::string& name, const std::string& addr);
        std::string getFullName() const;
        std::string getAddress() const;
        void displayInfo() const;
    };
    class Accident {
    private:
        std::string date; 
        std::string description;
    public:
        Accident(const std::string& d, const std::string& desc);
        std::string getDate() const;
        std::string getDescription() const;
        void displayInfo() const;
    };

    class Car {
    private:
        std::string regNumber;
        std::string engineNumber;
        std::string brand;
        std::string model;
        std::string color;
        bool isStolen;
        std::shared_ptr<Owner> currentOwner;
        std::vector<std::shared_ptr<Owner>> previousOwners;
        std::vector<std::shared_ptr<Accident>> accidents;
    public:
        Car(const std::string& reg, const std::string& eng, const std::string& br,
            const std::string& mod, const std::string& col, bool stolen = false);
        std::string getRegNumber() const;
        std::string getEngineNumber() const;
        std::string getBrand() const;
        std::string getModel() const;
        std::string getColor() const;
        bool getIsStolen() const;
        std::shared_ptr<Owner> getCurrentOwner() const;
        const std::vector<std::shared_ptr<Owner>>& getPreviousOwners() const;
        const std::vector<std::shared_ptr<Accident>>& getAccidents() const;
        void setCurrentOwner(std::shared_ptr<Owner> owner);
        void addPreviousOwner(std::shared_ptr<Owner> owner);
        void addAccident(std::shared_ptr<Accident> accident);
        void displayInfo() const;
    };
} 
