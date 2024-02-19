#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>

struct Resistor {
    std::string band1;
    std::string band2;
    std::string multiplier;
    std::string tolerance;
};

std::unordered_map<std::string, int> colorToDigit = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green", 5},
    {"blue", 6},
    {"violet", 7},
    {"grey", 8},
    {"white", 9}
};

std::unordered_map<std::string, int> colorToMultiplier = {
    {"black", 1},
    {"brown", 10},
    {"red", 100},
    {"orange", 1000},
    {"yellow", 10000},
    {"green", 100000},
    {"blue", 1000000},
    {"violet", 10000000},

    {"white", 100000000}
};

std::unordered_map<std::string, double> colorToTolerance = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},

    {"yellow", 5},
    {"green", 0.5},
    {"blue", 0.25},
    {"violet", 0.1},
    {"grey", 0.05},

    {"gold", 5},
    {"silver", 10}
};

Resistor inputResistor() {
    Resistor r;
    std::cout << "Enter the first band: ";
    while (true) {
        std::cin >> r.band1;
        std::transform(r.band1.begin(), r.band1.end(), r.band1.begin(), 
        [](unsigned char c) {return std::tolower(c);});
        if (colorToDigit.find(r.band1) != colorToDigit.end()) {
            break;
        }
        std::cout << "Invalid color, please enter a valid color: ";
    };

    std::cout << "Enter the second band: ";
    while (true) {
        std::cin >> r.band2;
        std::transform(r.band2.begin(), r.band2.end(), r.band2.begin(), 
        [](unsigned char c) {return std::tolower(c);});
        if (colorToDigit.find(r.band2) != colorToDigit.end()) {
            break;
        }
        std::cout << "Invalid color, please enter a valid color: ";
    };

    std::cout << "Enter the multiplier: ";
    while (true) {
        std::cin >> r.multiplier;
        std::transform(r.multiplier.begin(), r.multiplier.end(), r.multiplier.begin(), 
        [](unsigned char c) {return std::tolower(c);});
        if (colorToMultiplier.find(r.multiplier) != colorToMultiplier.end()) {
            break;
        }
        std::cout << "Invalid color, please enter a valid color: ";
    };

    std::cout << "Enter the tolerance: ";
    while (true) {
        std::cin >> r.tolerance;
        std::transform(r.tolerance.begin(), r.tolerance.end(), r.tolerance.begin(), 
        [](unsigned char c) {return std::tolower(c);});
        if (colorToTolerance.find(r.tolerance) != colorToTolerance.end()) {
            break;
        }
        std::cout << "Invalid color, please enter a valid color: ";
    };

    return r;
};



double calculateRating(const Resistor& resistor) {
    const std::string* band1 = &resistor.band1;
    const std::string* band2 = &resistor.band2;
    const std::string* multiplier = &resistor.multiplier;

    int band1Value = colorToDigit[*band1];
    int band2Value = colorToDigit[*band2];
    int multiplierValue = colorToMultiplier[*multiplier];

    double rating = (band1Value * 10 + band2Value) * multiplierValue;
    return rating;
}

double calculateTolerance(const Resistor& r) {

    const std::string* tolerance = &r.tolerance;
    double toleranceValue = colorToTolerance[*tolerance];

    return toleranceValue;
}

int main() {

    Resistor  r = inputResistor();
    double rating = calculateRating(r);

    double toleranceValue = calculateTolerance(r);

    std::cout << "The rating of the resistor is: " << rating << "ohms, +/- " << toleranceValue << "%" << std::endl;
}
