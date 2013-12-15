Blackjack Assignment
====================

**Optional Project  
COSC 501  
By Prof. H. Zhou  
Due: 12/15/2013**  

Write a program that simulates a simplified version of the game "BlackJack".

A deck of cards numbered 2 to 10, jacks, queens, kings, and aces is used, where jacks, queens and kings are counted as 10s, and aces are either 1 or 11 at your choice.  Any number can be repeated since the deck contains many cards. The computer starts by giving you two cards and shows you one of its cards, all of which are randomly picked. Then the computer asks you whether or not to want another card. This process stops when you say "no", or the total of your cards exceeds 21, in which case you automatically lose. If your value is under or equal to 21 and you decide to stay, the computer deals its cards until its total is greater than or equal to 17. If the computer's total is greater than 21, you win by default. The winner is the one with the highest score equal to or less than 21. You can double the hand if the total of the first two cards is 10 or 9. Once doubled, you will be allowed to ask for only one card (Only the bet is doubled, not the value of a hand). Whoever wins this hand, the payoff will be doubled too. You are welcome to enhance this version by adding the options of splitting and surrendering.

Write your program so that the game can be played 10 consecutive times with the winner of each game winning one point (two points if doubled). At the end of the 10 games print out the total winnings for you and the computer. The example below shows only a partial run. The output produced should be sent to the screen as well as an output file. Please submit your program and the output produced on a hard copy.

### Example

*Let us play one hand.*  
You: 7 9  
Me:  2  

*Do you want another card?*  
No

Let me pick one or more cards until the total  >= 17  
6 10        *(comment: you do not have to show the previous card)*  
I have 18 and you have 16 so I win!

*Let us play one hand.*  
You: 6 7  
Me: 10  

*Do you want another card?*  
yes  

You: 8.  
Your total now is 21.  

*Do you want another card?*  
No  

Let me pick one or more cards until the total  `>= 17` …  
Me: 9  
I have 19 and you have 21 so you win!  
…   

*Let us play one hand.*  
You: 6 10 4 
Me: Ace

*Do you want another card?*  
No

Let me pick one or more cards until the total  `>= 17` …
Me: 9

I have 20 and you have 20 so we draw.
…  

My winnings = 4
Your winnings = 5

### Random Number Code

The following is a sample program containing the random number generator available in C++. Make the changes necessary to fit your needs (You must have the statements shown in bold face in your program).

	#include <stdlib>
	#include <time>

	long seed;
	time_t *storage;
	storage = 0;

	seed = time(storage); // use the system clock to produce an initial time 

	srand(seed);  // to seed the random number generator

	k = 1;
	while(k <= 10)
	{
	  cout << rand() % 13 + 1;
	  k++;
	}    // produce 10 random numbers in the range of 1 to 13.

Good luck and enjoy the game