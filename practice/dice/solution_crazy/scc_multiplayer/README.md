Ship Captain Crew (Multiplayer)
===============================

Writing a multi-player game is usually more challenging than a single-player game.
This one permits as many to play as you like, by simply alternating turns.

This classic game is usually played with 5 six-sided dice, allowing 3 rolls to find
the ship (a 6), the captain (a 5), and a crew (a 4), with the remaining 2 dice being
the value of the cargo. In this variant, we'll use 4-, 6-, 8-, 10-, and 12-sided dice,
and flip the goal to finding the ship (a 1), the captain (a 2), and a crew (a 3).
Otherwise, the classic rules apply.

A voyage is attempted over 5 weeks, or rolls of 5 dice of 4, 6, 8, 10, and 12 sides 
respectively. As a merchant, you seek to earn money by leasing a ship ('1'), hiring 
a captain ('2'), and completing a full crew ('3'). If you succeed, then the sum of 
the remaining 2 dice is your commission. If you fail, then you are paid nothing, 
but if you use fewer than 5 rolls, you will receive a bonus for delivering your 
cargo early.

You MUST follow precedence - ship before or concurrent with captain, before or 
concurrent with crew. After a roll, type 5 characters to 'k'eep the corresponding die 
or 'd'iscard and reroll it. (Previous decisions are remembered, although you must always
type at least one k or d.) You may 'k'eep any dice from a previous roll, as long as you 
follow the precedence.

- Typing kddkd would 'k'eep the roll of the 4- and 10-sided dice, and reroll the rest. 
- Typing k would keep the 4-sided roll again, and keep or discard the rest the same as the previous roll.
- Typing kkkkk ends the game early if you get all 'keepers'.

The game is played until a merchant earns 47 crowns profit, although the other merchants
will be given one final turn to try to exceed that that merchant's profit.

A single-player version is shown in the peer directory [ship_captain_crew](../ship_captain_crew).
Other crazy challenge solutions may be found [here](../README.md).

