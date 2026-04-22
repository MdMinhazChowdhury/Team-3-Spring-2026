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
		std::cout << name << ", enter your bet amount: ";
		std::cin >> amount;
		if (amount > chips) {
			std::cout << "You don't have enough chips to bet that amount. Please enter a valid amount." << std::endl;
			return bet(); // Recursively ask for a valid amount
		}
		else 
		{
			chips -= amount; // Deduct the bet amount from the player's chips	
		}
		return amount;
	}

	void call()
	{
		std::cout << name << " calls." << std::endl;
	}

	int raise()
	{
		int amount;
		std::cout << name << ", enter your raise amount: ";
		std::cin >> amount;
		if (amount > chips) {
			std::cout << "You don't have enough chips to bet that amount. Please enter a valid amount." << std::endl;
			return raise(); // Recursively ask for a valid amount
		}
		else
		{
			chips -= amount; // Deduct the bet amount from the player's chips	
		}
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