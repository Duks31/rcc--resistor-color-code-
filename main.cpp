#include <iostream>

struct Resistor {
    int band1;
    int band2;
    int multiplier;
    double tolerance;
};

Resistor inputResistor() {
    Resistor r;
    std::cout << "Enter the first band: ";
    std::cin >> r.band1;
    std::cout << "Enter the second band: ";
    std::cin >> r.band2;
    std::cout << "Enter the multiplier: ";
    std::cin >> r.multiplier;
    std::cout << "Enter the tolerance: ";
    std::cin >> r.tolerance;
    return r;
};

double calculateRating(const Resistor& resistor) {
    const int* band1 = &resistor.band1;
    const int* band2 = &resistor.band2;
    const int* multiplier = &resistor.multiplier;

    double rating = (*band1 * 10 + *band2) * (*multiplier);

    return rating; 
}

int main() {

    Resistor  r = inputResistor();
    double rating = calculateRating(r);

    const double* tolerance = &r.tolerance;
    double toleranceValue = *tolerance;

    std::cout << "The rating of the resistor is: " << rating << "ohms, +/- " << toleranceValue << "%" << std::endl;
}
