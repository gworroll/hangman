# hangman
A simple hangman game in C++

## Requirements:
*nix system with /usr/share/dict/words

## Limitations
- Multiples of the same bad guess each count against you
- No seeding of RNG, so it's always the same word
- Only exit from game is Ctrl-C or losing.

## Building
Go to the directory the source file is and type:
g++ hangman.cpp 

Optionally you can use -o to give a name other than 'a.out'. 

Planned changes:
-Count each bad guess only once
-Seed RNG
-Exit or restart game when either winning or losing
-ASCII art
-Makefile
