#include "fonction.h"
//gcc -Wall -Wextra -Werror my_mastermind.c -L. -lmymastermind -o my_mastermind.exe

int main(int argc, char** argv) {
    int code[4];
    int attempts = 10;
    bool code_donne = false;

    //parcours des arguments reçu
    analyse_arguments(argc, argv, code, &attempts, &code_donne);

    //Si pas de code donné
    if (!code_donne) {
        printf("A random code will be generated.\n");
        generate_code(code);
    }

    //Le jeu
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    for (int i = 0; i < attempts; i++) {
        printf("---\nRound %d\n", i);
        int guess[4];
        bool guess_donne = read_guess(guess);

        if (!guess_donne) {
            return 0;
        }

        //boucle des pièces biens placées
        int well_placed = count_well_placed(code, guess);
        int misplaced = count_misplaced(code, guess, well_placed);

        if (victory(well_placed)) {
            printf("Congratz! You did it!\n");
            return 0;
        }

        printf("Well placed pieces: %d\n", well_placed);
        printf("Misplaced pieces: %d\n", misplaced);
    }
    return 0;
}