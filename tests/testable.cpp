//Javani moved testable.cpp into tests #include "Card.cpp"
#include "Deck.cpp"
#include "Human.cpp"
#include "Pot.cpp"
#include "PlayerFactory.cpp"
#include "GameState.cpp"
#include <iostream>

#pragma once

int main() {
	Deck myDeck;
	myDeck.Shuffle(); 

	for (int i = 0; i < 52; ++i)	 {
		Card card = myDeck.Deal();
		std::cout << "Dealt card: Suit = " << card.GetSuit(card) << ", Rank = " << card.GetRank(card) << std::endl;
	}

	// makes sure the shuffle function works and all 52 cards get dealt without any duplicates or missing cards.
	myDeck.~Deck(); // explicitly call the destructor to clear the deck

//creates human player using factory 
	Human playerT=PlayerFactory::createHumanPlayer("Alice", "123");

	//Added by Javani to tracke player info using GameState
	std:: string playerName="Alice";
	std:: string lastAction= "none";

	std::cout << "" << std::endl;
	Deck myDeck2;
	playerT.HoleCards[0] = myDeck2.Deal();
	playerT.HoleCards[1] = myDeck2.Deal();

	std::cout << "Player's hole cards: " << std::endl;
	std::cout << "Card 1: Suit = " << playerT.HoleCards[0].GetSuit(playerT.HoleCards[0])
		<< ", Rank = " << playerT.HoleCards[0].GetRank(playerT.HoleCards[0]) << std::endl;
	std::cout << "Card 2: Suit = " << playerT.HoleCards[1].GetSuit(playerT.HoleCards[1])
		<< ", Rank = " << playerT.HoleCards[1].GetRank(playerT.HoleCards[1]) << std::endl;

	int betAmount = playerT.bet();
	lastAction="bet";
  
	//Added by Javani to call and test saveGameState
	saveGameState(playerName, betAmount, lastAction);

	int raiseAmount = playerT.raise();
	lastAction="raise";

	playerT.fold();
	lastAction="fold";

	Pot myPot;
	myPot.addToPot(betAmount);
	std::cout << "Total amount in the pot: " << myPot.getTotalAmount() << std::endl;

	std:: string loadedName, loadedAction;
	int loadedChips;

	if(loadGameState(loadedName, loadedChips, loadedAction))
	{
		std:: cout << "\nLoaded Game State\n";
		std::cout << "Name: " << loadedName << std::endl;
        std::cout << "Chips: " << loadedChips << std::endl;
        std::cout << "Last Action: " << loadedAction << std::endl;
	}
	//myPot.playersInPot[0] = playerT.getId();
}
