/* 
COSC 501
Elliott Plack
Optional Project
12 Dec 2013           Due date: 15 Dec 2013
Problem: https://github.com/talllguy/BlackJack/blob/master/assignment.md
Psuedocode: https://github.com/talllguy/BlackJack/blob/master/blackjackPlanning.md
*/

#include <iostream>
#include <time.h>
using namespace std;

// global card deck variable
const int cardsDeck[52] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9,
10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1, 2, 3, 4,
5, 6, 7, 8, 9, 10, 10, 10, 10 }; // 52 cards, with 10 being face card

// functions
void random(); // random number setup
void initialize(int[]); // clear the hands
int deal(); // function to deal a card
int ace(int); // function to decide an ace's value
int handValue(int[]); // sums the value of a given hand
int handStatus(int[]);
bool doubleCheck(int[]); // checks if the hand value is doubled

int main()
{
	// enum
	enum gameStatus // what is the status of the game
	{
		inProgress = 0,
		win = 1,
		bust = 2
	};
	
	// structs
	struct player
	{
		int hand[10]; // the cards in the hand
		int value; // hand's value
		gameStatus status; // status of the game
		int winCounter = 0; // wins counter
	};
	player user, dealer;
	
	// variables
	int hands = 0; // counter for hands played
	bool doubled = false; // flag if doubled
	int statusFlag = 0; // until I figure out how to return enum
	char hit = 'n'; // want another card?

	// random set up
	random();
	
	// game
	while (hands < 10)
	{
		// initialize
		initialize(user.hand);
		initialize(dealer.hand);
		// deal cards
		user.hand[0] = deal();
		user.hand[1] = deal();
		dealer.hand[0] = deal();
		// display first deal
		cout << "Let's play a hand.\n";
		cout << "Your hand: " << user.hand[0] << " " << user.hand[1] << endl;
		cout << "My hand:   " << dealer.hand[0] << endl;
		// check if the hand is double-able
		doubled = doubleCheck(user.hand);
		// aces
		user.hand[0] = ace(user.hand[0]);
		user.hand[1] = ace(user.hand[1]);
		// update value of player hand
		user.value = handValue(user.hand);
		// update status
		user.status = (gameStatus)handStatus(user.hand);
		if (doubled == true)
		{
			user.hand[2] = deal();
			user.hand[2] = ace(user.hand[2]);
			cout << "Your next card is: " << user.hand[2];
			user.value = handValue(user.hand);
			user.status = (gameStatus)handStatus(user.hand);
			// determine fate
			if (user.status == 1)
			{
				cout << "You won!\n";
				user.winCounter++;
				user.winCounter++;
			}
			else
			{
				cout << "You lost!\n";
				dealer.winCounter++;
			}
		}
		else
		{
			int dealCount = 2; // counter for future deals
			cout << "Do you want another card? (Y/N): ";
			cin >> hit;
			while (hit == 'y' || hit == 'Y')
			{
				user.hand[dealCount] = deal();
				user.hand[dealCount] = ace(user.hand[dealCount]);
				cout << "Your next card is: " << user.hand[dealCount] << endl;
				// update value of player hand
				user.value = handValue(user.hand);
				// update status
				user.status = (gameStatus)handStatus(user.hand);
				// determine fate
				if (user.status == 1)
				{
					cout << "You won!\n";
					user.winCounter++;
					break;
				}
				else if (user.status == 2)
				{
					cout << "You lost!\n";
					dealer.winCounter++;
					break;
				}
				dealCount++;
				cout << "Do you want another card? (Y/N): ";
				cin >> hit;
			}

		}
		cout << "\nSCORE\n" << "You: " << user.winCounter << endl << "Me:  " << dealer.winCounter << endl << endl;
		hands++;
	}
	
	return 0;
}



void random()
{
	long seed;
	time_t *storage;
	storage = 0;
	seed = time(storage); // use the system clock to produce an initial time 
	srand(seed);  // to seed the random number generator
}

void initialize(int hand[])
{
	for (int i = 0; i < 10; i++)
	{
		hand[i] = 0;
	};
}

int deal()
{
	int cardIndex = 0; // random index value
	int card = 0; // actual card value to return

	cardIndex = rand() % 52 + 1;
	//cout << "Random index picked:" << cardIndex << endl; // testing output

	card = cardsDeck[cardIndex];
	//cout << "Card is " << card << endl;

	return card;
}

int handValue(int hand[])
{
	int sum = 0; // temp value
	for (int i = 0; i < 10; i++)
	{
		sum += hand[i];
	}
	return sum;
}

bool doubleCheck(int hand[])
{
	char doubleQ = 'N'; // ask the player if they want to double
	bool canDouble = false; // can it double
	bool doubleIt = false; //value to return
	// check if it can be doubled
	if (handValue(hand) == 9) 
		canDouble = true;
	else if (handValue(hand) == 10)
		canDouble = true;
	else
		canDouble = false;
	// if it can, does the player want to?
	if (canDouble == true)
	{
		cout << "You can double your bet, but only get one more card.\n"
			<< "Double it? (Y/N): ";
		cin >> doubleQ;
		switch (doubleQ)
		{
		case 'Y':
		case 'y':
			doubleIt = true;
			break;
		case 'N':
		case 'n':
			doubleIt = false;
			break;
		default:
			cout << "\aInvalid. Enter Y/N: ";
			cin >> doubleQ;
			break;
		}
	}

	return doubleIt;

}

int handStatus(int hand[])
{
	if (handValue(hand) < 21)
		return 0; // can continue
	else if (handValue(hand) == 21)
		return 1; // win
	else return 2; // bust
}

int ace(int card)
{
	int aceValue = 1; // value of ace to be asked to player
	if (card == 1)
	{
		cout << "Enter a value for that ace! (1 or 11): ";
		cin >> aceValue;
		return aceValue;
	}
	else
		return card;
}