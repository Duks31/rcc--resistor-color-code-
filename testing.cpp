#include <cassert>
#include <sstream>

// Function to simulate user input for testing
void simulateUserInput(const std::string& input) {
    std::istringstream inputBuffer(input);
    std::cin.rdbuf(inputBuffer.rdbuf());
}

void runTests() {
    // Test 1: Basic functionality
    Resistor testResistor = {"brown", "black", "red", "gold"};
    assert(calculateRating(testResistor) == 1000.0); // 10 * 100 (brown: 1, black: 0, red: 100, gold: x0.1)
    assert(calculateTolerance(testResistor) == 5.0); // gold: 5%

    // Test 2: Invalid color handling
    // (Assuming that the function should return a specific value for invalid input)
    Resistor invalidResistor = {"invalid_color", "green", "blue", "silver"};
    assert(calculateRating(invalidResistor) == -1.0); // Placeholder for an invalid result
    assert(calculateTolerance(invalidResistor) == -1.0); // Placeholder for an invalid result

    // Test 3: Edge cases - Lowest resistance
    Resistor lowestResistance = {"black", "black", "black", "brown"};
    assert(calculateRating(lowestResistance) == 1.0); // 0 * 10 + 0 * 1 (black: 0, black: 0, black: 0, brown: x10)

    // Test 4: Edge cases - Highest resistance
    Resistor highestResistance = {"white", "white", "white", "gold"};
    assert(calculateRating(highestResistance) == 99000000.0); // 9 * 10^7 * 10 (white: 9, white: 9, white: 9, gold: x0.1)
    assert(calculateTolerance(highestResistance) == 5.0); // gold: 5%

    // Test 5: Interactive Input and Error Handling
    simulateUserInput("invalid_color\nblue\nred\nsilver\n");
    Resistor interactiveResistor = inputResistor();
    assert(interactiveResistor.band1 == "blue");
    assert(interactiveResistor.band2 == "red");
    assert(interactiveResistor.multiplier == "silver");
    assert(interactiveResistor.tolerance == ""); // Placeholder for invalid input

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();

    // Your existing code for user interaction or further testing...

    return 0;
}
