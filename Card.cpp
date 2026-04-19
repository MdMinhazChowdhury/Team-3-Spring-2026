class Card {
public:
	enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };   // 0,1, 2, 3
    enum Rank 
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    };
    // starts with 1, not zero

	Card() : suit(CLUBS), rank(ACE) {}  // default constructor
    Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}  // constructor 

private:
    Suit suit;
    Rank rank;
};
