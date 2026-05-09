//created by Javani
#include <fstream>
#include <iostream>
#include <string>
// Saves and loads player state:
// name, chips, and last action
void saveGameState(std::string playerName, int chips, std::string action) {

    std::ofstream file("save.txt");

    if (!file) {
        std::cout << "Error: Could not open file for saving.\n";
        return;
    }

    // Save all values (space-separated)
    file << playerName << " " << chips << " " << action << std::endl;

    file.close();

    std::cout << "Game state saved successfully.\n";
}

// Load game state
// Uses references to return multiple values
bool loadGameState(std::string &playerName, int &chips, std::string &action) {

    std::ifstream file("save.txt");

    if (!file) {
        std::cout << "No saved game found.\n";
        return false;
    }

    // Read saved values
    file >> playerName >> chips >> action;

    file.close();

    std::cout << "Game state loaded successfully.\n";

    return true;
}