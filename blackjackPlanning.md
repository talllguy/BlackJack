BlackJack Pseudocode and Planning
=================================

## Notes from Discussion

Chatted with the professor. Here is a summary:

> The only hard part about this will be the ace. Could be 1 or 11.

>The deck is suit-less, however, it would be a good idea to use an
>array to pick from where it would be like [1,2,3,...10,10,10,1,2,
>... repeat]. The reason for this is there are three 10s so the
>chance of getting one should be higher. Use at least 4 copies each
>number to represent the deck.

>The user gets dealt two, and the dealer one. The dealer asks if
>you want more until you say no. Then it is the dealers turn. They
>must keep going until they have more than or equal 17. so if they
>had 16, they'd have to get another card, knowing that a 10 would
>bust them. If the users first two cards = 10 or 9, the game is worth
>two. Each game won is normally worth 1 point, and the game needs to
>repeat 10 times.
	 
## Planning

### Variables

- Deck. An array of 52 ints, with 10 repeating 3 times for the face cards
- Player struct
 - hand (int array)
 - status (inProgress, win, bust)
 - wins (int)
- Dealer struct
 - hand (int array)
 - status (inProgress, win, bust)
 - wins (int)
- Double flag
- Hands played counter

### Functions

- Pick a random card (dealing)
- Decide where ace should be 1 or 11
- Add up the value of the hand

## Psuedocode

- initialize functions and variables
- while loop to play 10 hands
- deal two cards to playerHand. If one is ace (1), ask for value.
   - Send value to value function. check if double, if 21
- deal one card to dealerHand. If is ace (1), ask for value.
- ask do you want another card // switch case
  - yes: deal one card to player hand.
    -  If is ace (1), ask for value.
    - show total (if total exceeds 21, end).
	- ask again (only if double is false) // while loop
  - no: continue
- dealer deals to dealerHand until total >= 17 // while loop
- compare both values, winner gets +1 point
- +1 to hand counter

