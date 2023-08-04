# Assessment test 2

Game of Twenty-One (Simpler blackjack)

Twenty-One is a card game played against the dealer.  Player(s) draw cards from the deck one by one, trying to get the sum of card values as close to 21 without exceeding it.  If a player goes over 21 they lose automatically.  If they get 21, they win automatically, otherwise after no player wants to pull a card, the closest to 21 wins (dealer winning in case of ties).

The game starts by the player(s) entering the table and the dealer giving each of them and himself one card, visible to everyone.  Then each player on his turn chooses to either draw a card or stay with his current score, giving the turn to the next player.  After all the players have their score, it is the dealer's turn to do the same.

A typical deck contains 52 cards, valued from 2-13 in each of the 4 suits: Clubs, Diamonds, Hearts, Spades.  Each suit also has ace card, which, in twenty-one is valued either 1 or 14, whichever the player prefers.  (So, a player drawing an ace after 5 would be 5 + 14 = 19, and if the player then drew another card and got a 3, the total would go over 21, and the ace would be counted as 1 and the total 5 + 1 + 3 = 9)

 

We build a game of Twenty-One.  In summary:

- (40p) Create a standard-compatible container type for a Deck (of cards), the deck should have following functionality
    - a shuffle() member function to shuffle the elements contained in the Deck container
    - a draw() member function to return the top card (and remove it from the Deck)
    - a top() and bottom() member functions to get a reference to top/bottom of the deck.
- (25p) Create rest of the suitable types representing the entities of the game
- (25p) Create the logic for the game, using the types you've created
- (10p) Create an user interface for the game (text-based is fine here)
Suggested things to start with, feel free to do something else if it suits your approach better:

- Create stub types for things you think are required (so just definitions, without much implementation yet)
- Implement core of the deck type (begin(), end(), element access) and parts that you don't need to think too much about and can get them running fast
- Start implementing the game logic and iterate/improve on the type definitions you started with
 
Half the score is a passing grade, it is not required (or even expected) to finish everything here in just 3 hours.

Bonus points awarded for:

- Reasonable error handling where appropriate!
- Code structuring
- Code clarity / readability
- Testability (there's no need to have actual unit tests due to lack of time, but the easier the code is to test the better)
- Good use of C++ type system
- Separation of UI from logic
