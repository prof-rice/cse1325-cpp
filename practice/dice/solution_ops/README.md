On a Roll
=========

This is a suggested solution to the "Improving the Die class" challenge presented in the [parent directory](../README.md).

Why have the value() and faces() methods been declared as const in both die.h and die.cpp? Without them, the compiler should issue the following error:

> passing ‘const Die’ as ‘this’ argument discards qualifiers

The qualifier is the "const Die& die" second parameter to your operator<< declaration. Because this die is required to be const, any methods called on die must respect the const qualifier as well. Assuming you called die.value() in operator<<, the compiler cannot ensure that this qualifier is respected unless value() includes the const qualifier as well.

(While faces() isn't called by operator<<, it is good practice to include the const qualifier on getters.)

The solution to the basic challenge is in peer directory [solution](../solution).
The solution to the crazy challenges are in the peer directory [solution_crazy](../solution_crazy).
The main page for Dice is [here](../README.md).
