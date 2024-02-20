// Importing neccessary libraries
#include <iostream>
#include "Resistor.h"

int main() {

    Resistor  r = inputResistor();
    double rating = calculateRating(r);
    double toleranceValue = calculateTolerance(r);

    std::cout << "The rating of the resistor is: " << rating << "ohms, +/- " << toleranceValue << "%" << std::endl;
}
