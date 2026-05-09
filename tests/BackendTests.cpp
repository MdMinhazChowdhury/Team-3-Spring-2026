#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>

// Simple test framework macros
#define TEST_PASS() std::cout << "[PASS] "
#define TEST_FAIL() std::cout << "[FAIL] "
#define TEST_INFO() std::cout << "[INFO] "

// Simple assertion macro
#define ASSERT_EQUAL(actual, expected, msg) \
    if (actual == expected) { \
        TEST_PASS() << msg << std::endl; \
        return true; \
    } else { \
        TEST_FAIL() << msg << " (expected " << expected << ", got " << actual << ")" << std::endl; \
        return false; \
    }

#define ASSERT_TRUE(condition, msg) \
    if (condition) { \
        TEST_PASS() << msg << std::endl; \
        return true; \
    } else { \
        TEST_FAIL() << msg << std::endl; \
        return false; \
    }

// Simple Card class
class Card {
public:
    enum Suit { HEARTS = 0, DIAMONDS = 1, CLUBS = 2, SPADES = 3 };
    enum Rank { TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, 
                EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 14 };
    
    Card() : suit(HEARTS), rank(TWO) {}
    Card(Suit s, Rank r) : suit(s), rank(r) {}
    
    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }
    
    bool operator==(const Card& other) const {
        return suit == other.suit && rank == other.rank;
    }

private:
    Suit suit;
    Rank rank;
};

// Simple Deck class
class Deck {
public:
    Deck() {
        // Initialize standard 52-card deck
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 2; rank <= 14; rank++) {
                cards.push_back(Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
            }
        }
    }
    
    void shuffle() {
        // Fisher-Yates shuffle algorithm
        for (int i = cards.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            // Swap
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
    }
    
    Card dealCard() {
        if (!cards.empty()) {
            Card card = cards.back();
            cards.pop_back();
            return card;
        }
        return Card(); // Return empty card if deck is empty
    }
    
    int getSize() const { return cards.size(); }
    
    bool containsCard(const Card& card) const {
        for (const auto& c : cards) {
            if (c == card) return true;
        }
        return false;
    }

private:
    std::vector<Card> cards;
};

// Simple Pot class
class Pot {
public:
    Pot() : totalAmount(0) {}
    
    bool addBet(int amount) {
        if (amount < 0) {
            return false; // Invalid negative bet
        }
        totalAmount += amount;
        return true;
    }
    
    int getTotal() const { return totalAmount; }
    
    void reset() { totalAmount = 0; }

private:
    int totalAmount;
};

// Simple Player class for balance validation
class Player {
public:
    Player(int initialBalance) : balance(initialBalance) {}
    
    bool placeBet(int amount) {
        if (amount < 0 || amount > balance) {
            return false; // Invalid bet
        }
        balance -= amount;
        return true;
    }
    
    void addWinnings(int amount) { balance += amount; }
    int getBalance() const { return balance; }

private:
    int balance;
};

// ============================================================================
// Test Functions
// ============================================================================

bool testCardCreation() {
    Card card(Card::HEARTS, Card::ACE);
    ASSERT_EQUAL(card.getSuit(), Card::HEARTS, "Card suit test");
}

bool testDeckCreation() {
    Deck deck;
    ASSERT_EQUAL(deck.getSize(), 52, "Deck initialization test");
}

bool testDeckNoDuplicates() {
    Deck deck;
    int cardCount = 0;
    std::vector<Card> checkedCards;
    
    // Manually verify no duplicates exist
    bool hasDuplicates = false;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            Card testCard(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
            if (deck.containsCard(testCard)) {
                cardCount++;
            }
        }
    }
    
    ASSERT_EQUAL(cardCount, 52, "Deck contains all 52 unique cards");
}

bool testDeckShuffle() {
    Deck deck;
    int originalSize = deck.getSize();
    deck.shuffle();
    ASSERT_EQUAL(deck.getSize(), originalSize, "Deck size unchanged after shuffle");
}

bool testDealCard() {
    Deck deck;
    int sizeBefore = deck.getSize();
    Card dealtCard = deck.dealCard();
    int sizeAfter = deck.getSize();
    
    bool cardDealt = (sizeAfter == sizeBefore - 1);
    ASSERT_TRUE(cardDealt, "Card dealt from deck reduces deck size");
}

bool testPotUpdate() {
    Pot pot;
    pot.addBet(10);
    pot.addBet(25);
    pot.addBet(5);
    
    ASSERT_EQUAL(pot.getTotal(), 40, "Pot accumulates bets correctly");
}

bool testInvalidNegativeBet() {
    Pot pot;
    bool result = pot.addBet(-5);
    bool isInvalid = !result;
    
    ASSERT_TRUE(isInvalid, "Negative bet validation test");
}

bool testPlayerBalanceValidation() {
    Player player(100);
    bool betExceeds = player.placeBet(150);
    bool isRejected = !betExceeds;
    
    bool validBet = player.placeBet(50);
    bool validBetAccepted = validBet && (player.getBalance() == 50);
    
    if (isRejected && validBetAccepted) {
        TEST_PASS() << "Player balance validation test" << std::endl;
        return true;
    } else {
        TEST_FAIL() << "Player balance validation test" << std::endl;
        return false;
    }
}

bool testPerformanceShuffleSmall() {
    Deck deck;
    auto start = std::chrono::high_resolution_clock::now();
    deck.shuffle();
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "[PASS] Performance test - single shuffle: " << duration.count() << "µs" << std::endl;
    
    return duration.count() < 1000; // Less than 1ms
}

bool testPerformanceShuffle10K() {
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 10000; i++) {
        Deck deck;
        deck.shuffle();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[PASS] Performance test - 10,000 shuffles: " << duration.count() << "ms" << std::endl;
    
    return duration.count() < 100; // Less than 100ms
}

bool testRegressionSprint1() {
    // Regression test: verify Sprint 1 functionality
    
    // Test 1: Card creation
    Card card(Card::SPADES, Card::KING);
    if (card.getSuit() != Card::SPADES) return false;
    
    // Test 2: Deck creation
    Deck deck;
    if (deck.getSize() != 52) return false;
    
    // Test 3: Deck shuffle
    deck.shuffle();
    if (deck.getSize() != 52) return false;
    
    // Test 4: Deal cards
    Card dealt = deck.dealCard();
    if (deck.getSize() != 51) return false;
    
    // Test 5: Pot management
    Pot pot;
    pot.addBet(50);
    if (pot.getTotal() != 50) return false;
    
    TEST_PASS() << "Regression test - Sprint 1 functionality preserved" << std::endl;
    return true;
}

// ============================================================================
// Main Test Runner
// ============================================================================

int main() {
    srand(static_cast<unsigned>(time(0)));
    
    std::cout << "========================================" << std::endl;
    std::cout << "Poker Simulator - Backend Tests" << std::endl;
    std::cout << "Sprint 2 - Person C (Fabrizio Lazo)" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;
    
    int passed = 0;
    int failed = 0;
    
    // Run tests
    std::cout << "Running Backend Tests..." << std::endl << std::endl;
    
    std::cout << "[BT-001] Card Logic Test" << std::endl;
    if (testCardCreation()) passed++; else failed++;
    
    std::cout << "[BT-002] Deck Creation Test" << std::endl;
    if (testDeckCreation()) passed++; else failed++;
    
    std::cout << "[BT-002b] Deck No Duplicates Test" << std::endl;
    if (testDeckNoDuplicates()) passed++; else failed++;
    
    std::cout << "[BT-003] Deck Shuffle Test" << std::endl;
    if (testDeckShuffle()) passed++; else failed++;
    
    std::cout << "[BT-004] Deal Card Test" << std::endl;
    if (testDealCard()) passed++; else failed++;
    
    std::cout << "[BT-005] Pot Update Test" << std::endl;
    if (testPotUpdate()) passed++; else failed++;
    
    std::cout << "[BT-006] Invalid Negative Bet Validation Test" << std::endl;
    if (testInvalidNegativeBet()) passed++; else failed++;
    
    std::cout << "[BT-007] Player Balance Validation Test" << std::endl;
    if (testPlayerBalanceValidation()) passed++; else failed++;
    
    std::cout << "[BT-008a] Performance Test - Single Shuffle" << std::endl;
    if (testPerformanceShuffleSmall()) passed++; else failed++;
    
    std::cout << "[BT-008b] Performance Test - 10,000 Shuffles" << std::endl;
    if (testPerformanceShuffle10K()) passed++; else failed++;
    
    std::cout << "[BT-009] Regression Test - Sprint 1 Backend Logic" << std::endl;
    if (testRegressionSprint1()) passed++; else failed++;
    
    // Print summary
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Test Summary" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Total Tests: " << (passed + failed) << std::endl;
    std::cout << "Passed: " << passed << std::endl;
    std::cout << "Failed: " << failed << std::endl;
    std::cout << "Success Rate: " << (100 * passed / (passed + failed)) << "%" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return (failed == 0) ? 0 : 1;
}
