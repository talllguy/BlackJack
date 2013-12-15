/* notes

The only hard part about this will be the ace. Could be 1 or 11.

The deck is suit-less, however, it would be a good idea to use an array to pick from
	where it would be like [1,2,3,...10,10,10,1,2,... repeat]. The reason for this is
	there are three 10s so the chance of getting one should be higher. Use at least 4
	copies each number to represent the deck.

The user gets dealt two, and the dealer one. The dealer asks if you want more until
	you say no. Then it is the dealers turn. They must keep going until they have
	more than or equal 17. so if they had 16, they'd have to get another card, knowing
	that a 10 would bust them. If the users first two cards = 10 or 9, the game is worth
	two. Each game won is normally worth 1 point, and the game needs to repeat 10 times.

*/

#include <iostream>
using namespace std;

int main()
{
	const int cardsDeck[52] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 1, 2, 3, 4,
	5, 6, 7, 8, 9, 10, 10, 10, }; // 52 cards, with 10 being face card
	int dealerWins;
	int playerWins;
	int dealerHand[10];
	int playerHand[10];
	int dealRand(int);
}

