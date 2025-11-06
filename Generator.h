#pragma once
#include <random>
#include <iostream>

class Generator {
public:
    virtual ~Generator() = default;
    virtual int generate() = 0;
};

class RandomGenerator : public Generator {
private:
    int min, max;
    std::mt19937 gen;
    
public:
    RandomGenerator(int min_val, int max_val) : min(min_val), max(max_val) {
        gen = std::mt19937(std::random_device{}());
    }
    
    int generate() override {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }
};

class KeyboardGenerator : public Generator {
public:
    int generate() override {
        int value;
        std::cin >> value;
        return value;
    }
};
