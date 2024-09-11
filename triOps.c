#include "main.h"


void triHightoLow(Etudiant_s etudiants[], int lines) {
    int i, j;
    Etudiant_s temp;
    for(i = 0; i < lines; i++) {
        for (j = 0; j < lines - i - 1; j++) {
            if(etudiants[j].note > etudiants[j + 1].note) {
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
}