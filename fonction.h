#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

void analyse_arguments(int argc, char* const argv[], int code[4], int* attempts, bool* code_donne);
bool validation_c(const char* code_recu, int code[4]);
bool validation_t(const char* attempts_recu);
void generate_code(int code[4]);
bool read_guess(int guess[4]);
int count_well_placed(const int code[4], const int guess[4]);
int count_misplaced(const int code[4], const int guess[4], int well_placed);
bool victory(int well_placed);

#endif