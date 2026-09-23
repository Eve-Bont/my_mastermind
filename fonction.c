#include "fonction.h"

void analyse_arguments(int argc, char* const argv[], int code[4], int* attempts, bool* code_donne) {
    bool attempts_donne = false;
    for(int i = 1; i < argc; i++) {
        //vérification code reçu est là et contient 4 chiffre
        if (strcmp(argv[i], "-c") == 0 && argc > i + 1 && argv[i+1][4] == '\0'){
            const char* code_recu = argv[i+1];
            *code_donne = validation_c(code_recu, code);
        }
        //vérification attempts recu est là.
        if (strcmp(argv[i], "-t") == 0 && argc > i + 1) {
            const char* attempts_recu = argv[i+1];
            attempts_donne = validation_t(attempts_recu);

            if (attempts_donne) {
                *attempts = atoi(argv[i+1]);
            }
        }
    }
}

bool validation_c(const char* code_recu, int code[4]) {
    for (int j = 0; j < 4; j++) {
        //vérification code reçu ne soit que des chiffres
        if (code_recu[j] >= '0' && code_recu[j] <= '8') {
            code[j] = code_recu[j] - '0';
        } else {
            return false;
        }
    }
    //vérification code reçu n'a pas de boublon
    for (int i = 0; i <4; i++) {
        for (int j = i + 1; j < 4; j++){
            if (code[i] == code[j]) {
                return false;
            }
        }
    }
    return true;
}

bool validation_t(const char* attempts_recu) {
    //parcours de attempts reçu.
    for (int j = 0; attempts_recu[j] != '\0'; j++) {
        if (attempts_recu[j] < '0' || attempts_recu[j] > '9') {
            return false;
        }
    }
    return true;
}

void generate_code(int code[4]) {
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

bool read_guess(int guess[4]) {
    bool guess_donne = false;
    while (!guess_donne) {
        guess_donne = true;
        char lu;
        for (int j = 0; j < 100; j++) {
            int resultat = read(0, &lu,1);
            
            if (resultat == 0) {
                guess_donne = false;
                return guess_donne;
            }
            if(lu == '\n'){
                if (j != 4){
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
        if (!guess_donne) {
            printf("Wrong input!\n");
        }
    }
    return guess_donne;
}

int count_well_placed(const int code[4], const int guess[4]) {
    int well_placed = 0;
    for (int i = 0; i < 4; i++) {
        if (code[i] == guess[i]) {
            well_placed ++;
        }
    }
    return well_placed;
}

int count_misplaced(const int code[4], const int guess[4], int well_placed) {
    int placed = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (code[i] == guess[j]) {
                placed++;
            }
        }
    }
    return placed - well_placed;
}

bool victory(int well_placed) {
    return well_placed == 4;
}