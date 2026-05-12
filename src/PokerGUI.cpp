//PokerGUI.cpp
// Javani

// provides a console-based GUI where
// users can interact with the poker system.
// Backend interaction is simulated through frontend
// menu workflows and player actions.

#include <iostream>
#include <string>

using namespace std;

// Displays menu options


void displayMenu() {

    cout << "\n====================================\n";
    cout << "         HIGH ACES POKER\n";
    cout << "====================================\n";

    cout << "1. Deal Cards\n";
    cout << "2. Bet\n";
    cout << "3. Raise\n";
    cout << "4. Fold\n";
    cout << "5. Check\n";
    cout << "6. Show Pot\n";
    cout << "7. Exit\n";

    cout << "====================================\n";
    cout << "Enter choice: ";
}


// Main GUI Controller

int main() {

    int choice = 0;
    int potAmount = 0;

    cout << "====================================\n";
    cout << "     HIGH ACES POKER SIMULATOR\n";
    cout << "====================================\n";

    while (choice != 7) {

        displayMenu();

        cin >> choice;

        // Prevent invalid type input

        if (cin.fail()) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input type.\n";
            continue;
        }

        // Prevent invalid menu input

        if (choice < 1 || choice > 7) {

            cout << "Invalid selection. Try again.\n";
            continue;
        }

        // Deal Cards

        if (choice == 1) {

            cout << "\nCards dealt successfully.\n";

            cout << "Card 1 -> Suit: HEARTS Rank: KING\n";
            cout << "Card 2 -> Suit: SPADES Rank: ACE\n";
        }

        // Bet

        else if (choice == 2) {

            int betAmount;

            cout << "Enter bet amount: ";
            cin >> betAmount;

            potAmount += betAmount;

            cout << "Bet added to pot.\n";
        }

        // Raise

        else if (choice == 3) {

            int raiseAmount;

            cout << "Enter raise amount: ";
            cin >> raiseAmount;

            potAmount += raiseAmount;

            cout << "Raise added to pot.\n";
        }

        // Fold

        else if (choice == 4) {

            cout << "Player folds.\n";
        }

        // Check

        else if (choice == 5) {

            cout << "Player checks.\n";
        }

        // Show Pot

        else if (choice == 6) {

            cout << "Current pot amount: "
                 << potAmount
                 << endl;
        }
    }

    cout << "\nExiting High Aces Poker...\n";

    return 0;
}