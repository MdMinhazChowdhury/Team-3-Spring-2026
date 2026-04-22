#include "Card.cpp"

#include <vector> // can also act like a stack 
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine, std::random_device
#include <chrono>    // For std::chrono::system_clock
					//using namespace std, the std:: access 

class Deck
{
private:
	std::vector<Card> cards;  // able to store 2 pieces of data (suit and rank) 

public:

	Deck()
	{
		// Initialize the deck with 52 cards (vector stack)
		for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
			for (int r = Card::ACE; r <= Card::KING; ++r) {
				cards.push_back(Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
			}
		}
	}
	~Deck()
	{
		// delete all cards in the deck (vector stack)
		cards.clear();
	}

	Card Deal()
	{
		if (cards.empty()) {
			throw std::runtime_error("Cannot deal from an empty deck.");
		}
		Card dealtCard = cards.back(); // Get the top card
		cards.pop_back();              // Remove it from the deck
		return dealtCard;
	}

	void Shuffle()
	{
		std::random_device rd;   // Obtain a random number from hardware
		std::default_random_engine engine(rd());  // creates a random engine and seeds it with the random number
		std::shuffle(cards.begin(), cards.end(), engine);  // Shuffle the deck using the random engine
	}

};