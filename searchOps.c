#include "main.h"

void searchByname(char name[]) {
    char buffer[MAX];
    Etudiant_s etudiant;
    FILE *fp;

    fp = fileops(file, "r");

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %s %s %s %f", &etudiant.uniqueId,
                                            etudiant.nom,
                                            etudiant.prenom,
                                            etudiant.naissance,
                                            etudiant.departement,
                                            &etudiant.note);
        if (strcmp(etudiant.nom, name) == 0) {
            printf("FOUND: %d %s %s %s %s %.2f\n", etudiant.uniqueId,
                                                etudiant.nom,
                                                etudiant.prenom,
                                                etudiant.naissance,
                                                etudiant.departement,
                                                etudiant.note);
        }
    }
    fclose(fp);
}

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
            printf("found one\n");
            counteur++;
        }
    }
    fclose(fp);

    return counteur;
}


void rechercheOps(int choix) {
    int select;
    char name[MAX];
    char *departments[] = {INFO, MECH, RH, JUR};
    if (choix == 1) {
        printf("Enter le nom d'etudiant a recherche:");
        scanf("%s", name);
        searchByname(name);
    } else if (choix == 2){
            printf("1: informatique\n");
            printf("2: mechanique\n");
            printf("3: resource humaine\n");
            printf("4: juridique\n");
            printf("Enter votre Selection: ");
            scanf("%d", &select);
            /*{
                clear_buffer();
                continue;
            }
            // BUG: Verifie le max index dans le tableau
            if (select <= 0)
            {
                printf("Selection incorrect\n");
                clear_buffer();
                continue;
            }*/
        // BUG: index departement Control
        printf("le nombre des etudiant dans %s est %d\n",  departments[select - 1], searchBydeprtement(departments[select - 1]));
    }
}