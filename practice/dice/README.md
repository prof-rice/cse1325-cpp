On a Roll
=========

This is an optional, fun practice challege with C++. The solution is at the end!

Background
----------

Statisticians have long used well-balanced [Platonic solids](https://en.wikipedia.org/wiki/Platonic_solid) with a different integer inscribed on each face to generate various random distributions of numbers. The most common of these solids in the statistical realm, the cube, has six sides and is usually inscribed with 1 through 6. For example, generating a secure password (*highly* recommended) can be accomplished with 5 such *dice* (as they are called - the singular is *die*) and a table from [Diceware](https://theworld.com/~reinhold/diceware.html).

The other Platonic solids have 4, 8, 12, and 20 sides, although non-Platonic solids are also sometimes used, such as solids with 10, 16, 24, 30, 50, 100, or even 144 sides. A few of my favorite dice for *statistical research* are here. The Platonics are yellow.

![Various dice](polyhedral.png)


Prof's Provocative Programming Prompt
-------------------------------------

### Writing the Die class

A die is a natural *object*, don't you think?

-   It has an attribute representing its number of faces (\_faces and faces()), which never changes once it is manufactured or 3D printed (*constructed*).
-   It has one face that is pointing upward (\_value and value()), which may change each time it is rolled (roll()).

Create the above class Die with the attributes and methods listed. These are also represented in the Unified Modeling Language (UML) class diagram below.

![UML diagram for class Die](die.png)


### Testing the Die class

Write a simple test / demonstration program that rolls and prints the value of each of the Platonic dice (i.e., with 4, 6, 8, 12, and 20 sides) 20 times.

### Using the Die class

Then write a main function that that asks for (1) the number of dice to roll n, (2) the number of faces per die f, and (3) the number of times to roll them r.

Instance n instances of class Die, passing f as a parameter, storing each instance in a vector.

Then iterate over the vector r times. Each iteration:

-   Call method roll() on each instance in the vector to reroll the die.
-   Add the value to a local variable sum, which starts at 0 each iteration.
-   Print out the value of each die (using the value() getter).
-   Print out the sum of all of the dice for this iteration (local variable sum).

Print each roll of dice on a separate line, showing the roll number in sequence, each die value rolled, and the sum of the dice in that roll. Include a working Makefile.

Remember not to create ANY local variables in main() to contain information that is already managed by your class. That's what the class is for!

One possible output to the basic challenge may look like this:

![Example output](demo.png)

### Improving the Die class

Add an operator\<\< overloaded operator. In all of your code, replace your "std::cout \<\< die.value()" with simply "std::cout \<\< die". Better? Better!

### Going *crazy*

Let your imagination run wild. **Write any practical program that uses your Die class.** Here are some examples, but don't let that stop you. Even a relatively simple practical program is extremely educational, while games can be quite fun and extend your understanding!

-   **Statistics** (suggested solution) - Baseline your Bonus main() function, but allow for a different number of faces on each die during a run.  Then calculate the mean, median, and mode for the rolls of those mixed dice.

-   **Table-Top Appliance** - I've heard of some obscure tabletop games that use Platonic dice to determine the results of player decisions, combat, and / or random events. Build a menu-driven app that quickly performs common rolls with a single command for a specific game of your choosing, and also allows for any other possible roll with a bit more effort.

-   **Dice Games** - Search for [simple dice games](https://duckduckgo.com/?q=simple+dice+games&t=h_&ia=web) and write one using your Die class. For example: 

  - **Formula 80** - The classic race-by-rolling-dice, with some decisions thrown in. Each driver starts at position 0. Each turn, they add the value of two 4-sided dice to their position. The winner is the first driver to 80 (which happens to be the standard number of characters across a terminal, should that give you any ideas).
  
    Once it works, jazz it up a little. For example, if both dice rolled have the same value ("doubles"), the driver may move as usual OR "shift" either die to the next larger Platonic, trading their move this turn for potentially faster movement on future turns. (I'll leave to you the math as to when this is advantageous, if you like!)

  - **Ship Captain Crew** (2 suggested solutions) - [Ship Captain Crew](https://en.wikipedia.org/wiki/Ship,_captain,_and_crew) is classically played with 5 6-sided dice. The object is to hire a ship (6), captain (5), and crew (4) over 3 rolls. After each roll, the player may keep a ship. If a ship is kept, a captain may also be kept. If a captain is kept, then a crew may also be kept. If a crew is kept, then any of the remaining two dice may be kept. If a ship, captain, and crew are all found, the score (the "cargo") is the sum of the remaining two dice, otherwise the score is zero. The winner has (of course) the highest score, either after one game or in a "first to 21" tournament.
  
    For a version using one each of the five Platonic dice, redefine the ship as 1, the captain as 2, and the crew as 3, since these are common to all Platonic dice. Since more faces make finding the ship, captain, and crew more difficult, also allow five rolls instead of three, with keeper rules as with the classic game. Also, since scores tend to be higher, set the tournament goal to (say) 47.
    
    As another twist, award a bonus for "early delivery" - add the square of the rolls not used. For example, if the ship sailed after 3 rolls instead of 5 (2 turns early), with a cargo of 7, then the score for that voyage is 2*2 + 7 = 11. Had it be completed in 2 rolls (3 turns early), the score would have been 3*3 + 7 = 16. 

  - **Liar's Dice** - In classic [Liar's Dice](https://en.wikipedia.org/wiki/Liar%27s_dice), as seen in *Pirates of the Caribbean: Dead Man's Chest*, each player secretly rolls five 6-sided dice and notes their values. Each player then "bids" in turn, predicting how many of a particular value will be found on ALL players' dice. Each bid must be the same number of a larger value, e.g., from three 4s to three 6s, OR a larger number of any value dice, e.g., from three 4s to four 1s. Rather than bid, a player may call "Liar!", asserting that the most recent bid is incorrect. Whan all players except the bidder call "Liar!", all dice are revealed. If the bidder is correct, he or she receives points equal to the number of other players. If the bidder is incorrect, each of the other players receive a point. 
  
    [Other variations are available](https://www.dicegamedepot.com/liars-dice-rules/).
  
    For a version using one each of the five Platonic dice, roll the Platonic dice set for each player, then clear the screen before the next player's roll (printing 80 newlines works just fine). Then, once the bidding (outside the program) ends, show the number of times each possible value (1 to 20) appears across all hands. The bidding is more interesting in the Platonic variant, as the higher values are more rare (how many 20s could their be with 5 players?).

### Checking your work

Suggested solutions are available for the [basic challenge](solution/README.md), the [improved challenge](solution_ops/README.md), and a few of the [going crazy challenges](solution_crazy/README.md).


