#include "main.h"

int searchBydeprtement(char departement[])
{
    char buffer[MAX];
    int counteur = 0;
    Etudiant_s etudiant;
    FILE *fp;

    fp = fileops(file, "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%d %s %s %s %s %f", &etudiant.uniqueId,
               etudiant.nom,
               etudiant.prenom,
               etudiant.naissance,
               etudiant.departement,
               &etudiant.note);

        if (strcmp(etudiant.departement, departement) == 0)
        {
            printf("%s\n", departement);
            counteur++;
        }
    }
    fclose(fp);

    return counteur;
}