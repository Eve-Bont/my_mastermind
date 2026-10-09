# Welcome to My Mastermind

---

## Task

The goal of this project is to recreate the Mastermind game in C.
The player must guess a secret code made of four distinct digits, ranging from 0 to 8, within a limited number of attempts. After each guess, the program provides feedback to help the player find the correct code.

## Description

The program generates a random secret code or accepts a custom code provided through command-line arguments.
The player has 10 attempts by default, but this number can be changed using the `-t` option.
After each guess, the program displays:
* **Well placed pieces:** the number of digits that are correct and in the right position.
* **Misplaced pieces:** the number of correct digits that are in the wrong position.
The program validates each guess to ensure that it contains exactly four distinct digits between 0 and 8.
The game ends when the player finds the secret code or runs out of attempts.

## Installation

Compile the project using the provided Makefile:
```bash
make
```
To remove the compiled object files:
```bash
make clean
```
To remove all generated files, including the executable:
```bash
make fclean
```
To rebuild the project from scratch:

```bash
make re
```

## Usage

Run the program with the default settings:
```bash
./my_mastermind
```
Run the program with a custom secret code:
```bash
./my_mastermind -c 1234
```
Set a custom number of attempts:
```bash
./my_mastermind -t 5
```
Use both options together:
```bash
./my_mastermind -c 1234 -t 5
```
During the game, enter a four-digit guess and press Enter. The program will tell you how many digits are well placed and misplaced.

Example:
```text
Will you find the secret code?
Please enter a valid guess
---
Round 0
1234
Well placed pieces: 2
Misplaced pieces: 1
```

If you find the secret code, the program displays a victory message.

### The Core Team

Made at Qwasar SV -- Software Engineering School