#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

// Card struct
struct Card {
    string rank;
    string suit;
};

// Create a deck of 52 cards
vector<Card> createDeck() {
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<Card> deck;

    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck.push_back(Card{rank, suit});
        }
    }

    return deck;
}

// Calculate the total value of a hand
int calculateScore(const vector<Card>& hand) {
    int total = 0;
    int aces = 0;

    for (const auto& card : hand) {
        if (card.rank == "Ace") {
            total += 11;
            aces++;
        } else if (card.rank == "King" || card.rank == "Queen" || card.rank == "Jack") {
            total += 10;
        } else {
            total += stoi(card.rank);
        }
    }

    // Convert Aces from 11 to 1 if total is too high
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    return total;
}

// Display hand
void displayHand(const vector<Card>& hand, bool hideFirst = false) {
    for (size_t i = 0; i < hand.size(); i++) {
        if (i == 0 && hideFirst) {
            cout << "[Hidden Card]" << endl;
        } else {
            cout << hand[i].rank << " of " << hand[i].suit << endl;
        }
    }
}

// Draw a card
Card drawCard(vector<Card>& deck) {
    Card drawn = deck.back();
    deck.pop_back();
    return drawn;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<Card> deck = createDeck();

    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    vector<Card> playerHand;
    vector<Card> dealerHand;

    // Initial deal
    playerHand.push_back(drawCard(deck));
    dealerHand.push_back(drawCard(deck));
    playerHand.push_back(drawCard(deck));
    dealerHand.push_back(drawCard(deck));

    cout << "Your hand:" << endl;
    displayHand(playerHand);
    cout << "Total: " << calculateScore(playerHand) << "\n\n";

    cout << "Dealer's hand:" << endl;
    displayHand(dealerHand, true);
    cout << "\n";

    // Player's turn
    while (true) {
        string choice;
        cout << "Do you want to hit or stand? ";
        cin >> choice;

        if (choice == "hit") {
            playerHand.push_back(drawCard(deck));
            cout << "You drew: " << playerHand.back().rank << " of " << playerHand.back().suit << endl;
            int score = calculateScore(playerHand);
            cout << "Total: " << score << endl;

            if (score > 21) {
                cout << "You bust! Dealer wins.\n";
                return 0;
            }
        } else if (choice == "stand") {
            break;
        } else {
            cout << "Invalid input. Please type 'hit' or 'stand'.\n";
        }
    }

    // Dealer's turn
    cout << "\nDealer's hand:" << endl;
    displayHand(dealerHand);
    int dealerScore = calculateScore(dealerHand);
    cout << "Dealer's total: " << dealerScore << endl;

    while (dealerScore < 17) {
        dealerHand.push_back(drawCard(deck));
        cout << "Dealer drew: " << dealerHand.back().rank << " of " << dealerHand.back().suit << endl;
        dealerScore = calculateScore(dealerHand);
        cout << "Dealer's total: " << dealerScore << endl;
    }

    int playerScore = calculateScore(playerHand);

    // Results
    cout << "\nFinal Results:\n";
    cout << "Your score: " << playerScore << endl;
    cout << "Dealer's score: " << dealerScore << endl;

    if (dealerScore > 21 || playerScore > dealerScore) {
        cout << "You win!" << endl;
    } else if (dealerScore == playerScore) {
        cout << "It's a tie! Dealer Wins!" << endl;
    } else {
        cout << "Dealer wins!" << endl;
    }

    return 0;
}
