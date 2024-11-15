// WordValidatorTest.cpp
#include <iostream>
#include "WordValidator.h"
#include "Grid.h"

void testWordValidation() {
    // Test setup
    std::vector<std::string> wordList = {"CAT", "DOG", "RAT"};
    Grid grid(10);
    WordValidator validator(wordList, grid);

    // Sample inputs and expected outputs
    std::cout << "Test 1: Valid word 'CAT'\n";
    std::cout << "Input: CAT\n";
    std::cout << "Expected: true\n";
    std::cout << "Result: " << (validator.isValidWord("CAT") ? "true" : "false") << "\n\n";

    std::cout << "Test 2: Invalid word 'BAT'\n"; 
    std::cout << "Input: BAT\n";
    std::cout << "Expected: false\n";
    std::cout << "Result: " << (validator.isValidWord("BAT") ? "true" : "false") << "\n\n";
}

int main() {
    testWordValidation();
    return 0;
}