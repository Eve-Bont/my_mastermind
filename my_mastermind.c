#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    int code[4];
    int attempts = 10;
    bool code_donne = false;
    bool attempts_donne = false;

    //parcours des arguments reçu
    for(int i = 1; i < argc; i++) {
        //vérification code reçu est là et contient 4 chiffre
        if (strcmp(argv[i], "-c") == 0 && argc > i + 1 && argv[i+1][4] == '\0'){
            code_donne = true;
            char* code_recu = argv[i+1];
            //parcours de code reçu
            for (int j = 0; j < 4; j++) {
                //vérification code reçu n'est que des chiffres
                if (code_recu[j] >= '0' && code_recu[j] <= '8') {
                    code[j] = code_recu[j] - '0';
                } else {
                    code_donne = false;
                }
            }
            //vérification code reçu n'a pas de boublon
            if (code_donne) {
                for (int i = 0; i <4; i++) {
                    for (int j = i + 1; j < 4; j++){
                        if (code[i] == code[j]) {
                            code_donne = false;
                        }
                    }
                }
            }
        }
        //vérification attempts recu est là.
        if (strcmp(argv[i], "-t") == 0 && argc > i + 1) {
            attempts_donne = true;
            char* attempts_recu = argv[i+1];
            //parcours de attempts reçu.
            for (int j = 0; attempts_recu[j] != '\0'; j++) {
                if (attempts_recu[j] < '0' || attempts_recu[j] > '9') {
                    attempts_donne = false;
                }
            }
            if (attempts_donne) {
                attempts = atoi(argv[i+1]);
            }
        }
    }

    //Si pas de code donné
    if (code_donne != true) {
        printf("A random code will be generated.\n");
        srand(time(NULL));
        code[0] = rand() % 9;
        code[1] = rand() % 9;

        while (code[1] == code[0]){
            code[1] = rand() % 9;
        }
        code[2] = rand() % 9;
        while(code[2] == code[0] || code[2] == code[1]) {
            code[2] = rand() % 9;
        }
        code[3] = rand() % 9;
        while(code[3] == code[0] || code[3] == code[1] || code[3] == code[2]) {
            code[3] = rand() % 9;
        }
    }

    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    for (int i = 0; i < attempts; i++) {
        printf("---\nRound %d\n", i);
        bool guess_donne = false;
        int guess[4];
        while (guess_donne != true) {
            guess_donne = true;
            char lu;
            for (int j = 0; j < 100; j++) {
                int resultat = read(0, &lu,1);
            
                if (resultat == 0) {
                    return 0;
                }
                if(lu == '\n'){
                    if (j == 4){
                    } else {
                        guess_donne = false;
                    }
                    break;
                }
                if (lu < '0' || lu > '8') {
                    guess_donne = false;
                } else if (j < 4) {
                    guess[j] = lu - '0';
                }
            }
            if (guess_donne) {
                for (int j = 0; j < 4; j++) {
                    for (int h = j + 1; h < 4; h++){
                        if (guess[j] == guess[h]) {
                            guess_donne = false;
                        }
                    }
            }
            }
            if (guess_donne != true) {
                printf("Wrong input!\n");
            }
        }

        int well_placed = 0, misplaced = 0, placed = 0;
        //boucle des pièces biens placées
        for (int i = 0; i < 4; i++) {
            if (code[i] == guess[i]) {
                well_placed ++;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (code[i] == guess[j]) {
                    placed++;
                }
            }
        }
        misplaced = placed - well_placed;
        if (well_placed == 4) {
            printf("Congratz! You did it!\n");
            return 0;
        }
        printf("Well placed pieces: %d\n", well_placed);
        printf("Misplaced pieces: %d\n", misplaced);
    }
    return 0;
}