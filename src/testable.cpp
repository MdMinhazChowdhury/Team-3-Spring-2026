#include "Card.cpp"
#include "Deck.cpp"
#include "Human.cpp"
#include "Pot.cpp"

#pragma once

int main_backup() {
	Deck myDeck;
	myDeck.Shuffle(); 
	for (int i = 0; i < 52; ++i)	 {
		Card card = myDeck.Deal();
		std::cout << "Dealt card: Suit = " << card.GetSuit(card) << ", Rank = " << card.GetRank(card) << std::endl;
	}
	// makes sure the shuffle function works and all 52 cards get dealt without any duplicates or missing cards.
	myDeck.~Deck(); // explicitly call the destructor to clear the deck


	Human playerT("Alice", "123");

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

	int raiseAmount = playerT.raise();

	playerT.fold();

	Pot myPot;
	myPot.addToPot(betAmount);
	std::cout << "Total amount in the pot: " << myPot.getTotalAmount() << std::endl;

	return 0;
	//myPot.playersInPot[0] = playerT.getId();
}
