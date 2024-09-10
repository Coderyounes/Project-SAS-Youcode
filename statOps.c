#include "main.h"

int totaletudiant()
{
    FILE *fp;
    int count;

    fp = fileops(file, "r");
    count = countlines(fp);

    printf("Total Etudiant: %d Etudiants\n", count);

    return count;
}

int totalBydeprtement(char departement[])
{
}
