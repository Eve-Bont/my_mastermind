# Welcome to My Mastermind

---

## Task

The goal of this project is to recreate the Mastermind game in C. The player must guess a secret code within a limited number of attempts.

## Description

The program generates a secret code consisting of four distinct digits, each ranging from `0` to `8`.

After each guess, the program indicates:
* The number of well-placed pieces: digits that are correct and in the correct position.
* The number of misplaced pieces: correct digits that are in the wrong position.

The player has 10 attempts by default to guess the code.

The program also supports command-line options:
* `-c`: Sets a custom secret code.
* `-t`: Sets the maximum number of attempts.

The player's input is checked to ensure that it contains four distinct digits in the allowed range.

## Installation

Clone the repository and navigate to the project directory.

Compile the program using the provided Makefile:
```bash
make
```

To remove the generated object files:
```bash
make clean
```

To remove all generated files, including the executable:
```bash
make fclean
```

To clean and recompile the project:
```bash
make re
```

## Usage

Start the game with a randomly generated code and 10 attempts:
```bash
./my_mastermind
```

Set a custom secret code:
```bash
./my_mastermind -c 1234
```

Set the maximum number of attempts:
```bash
./my_mastermind -t 5
```

Combine both options:
```bash
./my_mastermind -c 1234 -t 5
```

Follow the instructions displayed in the terminal to enter your guesses.

### The Core Team

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>