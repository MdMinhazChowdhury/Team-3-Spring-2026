// created by Javani
#include "PlayerFactory.cpp"
#include <cassert>
#include <iostream>

// Test to check if PlayerFactory creates a Human player correctly
void testCreateHumanPlayer() {
    
    // Create player using factory
    Human p = PlayerFactory::createHumanPlayer("TestUser", "001");

    // If program reaches here without crashing, test passes
    std::cout << "testCreateHumanPlayer passed!" << std::endl;
}

// Main function to run all tests
int main() {
    
    testCreateHumanPlayer();

    return 0;
}