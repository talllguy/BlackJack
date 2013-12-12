#pragma once
class blackjack
{
public:
	blackjack();
	~blackjack();
	const int cardsDeck[52] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 1, 2, 3, 4,
		5, 6, 7, 8, 9, 10, 10, 10, }; // 52 cards, with 10 being face card
	int dealerWins;
	int playerWins;
	int dealerHand[10];
	int playerHand[10];
	int dealRand(int);
};

