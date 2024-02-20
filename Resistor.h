#ifndef resistor_h
#define resistor_h

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>

// Defining the Resistor struct
struct Resistor {
    std::string band1;
    std::string band2;
    std::string multiplier;
    std::string tolerance;
};

extern std::unordered_map<std::string, int> colorToDigit;
extern std::unordered_map<std::string, int> colorToMultiplier;
extern std::unordered_map<std::string, double> colorToTolerance;

Resistor inputResistor();
double calculateRating(const Resistor& r);
double calculateTolerance(const Resistor& r);

#endif