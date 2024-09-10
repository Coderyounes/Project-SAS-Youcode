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