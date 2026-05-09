#include "Card.cpp"

#include <iostream>
#include <string>

class Human
{
private:
	std:: string name;
	std::string id;
	int chips = 500;  // Amount of chips the player has	

public:
	Human(std::string playerName, std::string playerId) : name(playerName), id(playerId) {}

	int bet()
	{
		int amount;
		//Javani changed this for more robust input validation
		std::cout << name << ", enter your bet amount: ";
		// Validate input: must be a number, > 0, and <= chips
while (!(std::cin >> amount) || amount <= 0 || amount > chips) {
    std::cout << "Invalid input. Enter a valid amount: ";
    
    // Clear error flags
    std::cin.clear();
    
    // Ignore bad input
    std::cin.ignore(1000, '\n');
}

chips -= amount; // Deduct the bet amount from the player's chips	
		
		return amount;
	}

	void call()
	{
		std::cout << name << " calls." << std::endl;
	}

	int raise()
	{
		int amount;
		//Javani changed this for more robust input validation
		std::cout << name << ", enter your bet amount: ";
		// Validate input: must be a number, > 0, and <= chips
while (!(std::cin >> amount) || amount <= 0 || amount > chips) {
    std::cout << "Invalid input. Enter a valid amount: ";
    
    // Clear error flags
    std::cin.clear();
    
    // Ignore bad input
    std::cin.ignore(1000, '\n');
}

chips -= amount; // Deduct the bet amount from the player's chips	
		
		return amount;
	}
	void fold() 
	{
		std::cout << name << " folds." << std::endl;
	}

	void check()
	{
		std::cout << name << " checks." << std::endl;
	}

	int allIn()
	{
		std::cout << name << " goes all-in!" << std::endl;
		int amount = chips; 
		chips = 0;
		return amount;
	}	

	Card HoleCards[2];  // Two hole cards for the player
};