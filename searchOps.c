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


void rechercheOps(int choix) {
    char *departments[] = {INFO, MECH, RH, JUR};
    if (choix == 1) {
        // function recherche par nom
    } else if (choix == 2){
        printf("Entree la nouveau departement:\n(1): informatique\n(2): mechanique\n(3): resource_humaine\n(4): juridique\nChoisir: ");
        scanf("%d", &choix);
        // BUG: index departement Control
        searchBydeprtement(departments[choix - 1]);
    }   
}