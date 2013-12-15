/* 



*/

#include <iostream>
#include <time.h>
using namespace std;

// global card deck variable
const int cardsDeck[52] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9,
10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 1, 2, 3, 4,
5, 6, 7, 8, 9, 10, 10, 10, }; // 52 cards, with 10 being face card

// functions
void random(); // random number setup
int deal(); // function to deal a card
int ace(int); // function to decide an ace's value
int handValue(int[]); // sums the value of a given hand

int main()
{
	// enum
	enum gameStatus // what is the status of the game
	{
		inProgress,win,bust
	};
	
	// structs
	struct player
	{
		int hand[10];
		gameStatus status;
		int winCounter;
	};
	player user/*, dealer*/;
	
	// variables
	int hands = 0; // counter for hands played

	// random set up
	random();
	
	// game
	while (hands < 10)
	{
		user.hand[0] = deal();
		user.hand[1] = deal();

		cout << "Let's play a hand.\n";
		cout << "Your hand: \n";
		cout << user.hand[0] << " " << user.hand[1] << endl;

		cin >> hands;
	}
	
	return 0;
}

int deal()
{
	int cardIndex = 0; // random index value
	int card = 0; // actual card value to return

	cardIndex = rand() % 52;
	//cout << "Random index picked:" << cardIndex << endl; // testing output

	card = cardsDeck[cardIndex];
	//cout << "Card is " << card << endl;

	return card;
}

void random()
{
	long seed;
	time_t *storage;
	storage = 0;
	seed = time(storage); // use the system clock to produce an initial time 
	srand(seed);  // to seed the random number generator
}