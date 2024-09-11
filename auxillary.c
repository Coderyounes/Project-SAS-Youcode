#include "main.h"

void Welcome()
{
    printf("\n\tWelcome\n");
    printf("1: Ajouter un(e) Etudiant(s) \n");
    printf("2: Afficher Tous les Etudiants\n");
    printf("3: Modifier un(e) Etudiant(e) \n");
    printf("4: Supprimer un(e) Etudiant(e)\n");
    printf("5: Recherche a un(e) Etudiant(e)\n");
    printf("6: Tri les Etudiants\n");
    printf("7: Calculer des Statistique\n");
    printf("0: Quitter le Program\n");
}

void clear_buffer()
{
    int c;
    printf("Invalid input\n");
    while ((c = getchar()) != '\n')
        ;
}

int countlines(FILE *fp)
{
    char buffer[MAX];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), fp))
    {
        count++;
    }
    rewind(fp);
    return count;
}

void printArray(Etudiant_s etudiants[], int lines) {
    int k;
    for (k = 0; k < lines; k++) {
        printf("%d %s %s %s %s %.2f\n", etudiants[k].uniqueId,
                                    etudiants[k].nom,
                                    etudiants[k].prenom,
                                    etudiants[k].naissance,
                                    etudiants[k].departement,
                                    etudiants[k].note);
    }
}

void triforTop(Etudiant_s etudiants[], int lines) {
    int i, j;
    Etudiant_s temp;
    for(i = 0; i < lines; i++) {
        for (j = 0; j < lines - i - 1; j++) {
            if(etudiants[j].note < etudiants[j + 1].note) {
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
    printArray(etudiants, 3);
}