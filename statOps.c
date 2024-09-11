#include "main.h"

int totaletudiant()
{
    FILE *fp;
    int count;

    fp = fileops(file, "r");
    count = countlines(fp);

    return count;
}

int totalBydeprtement(char departement[])
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

float moyenneGlobal()
{
    char buffer[MAX];
    float total;
    int lines;
    Etudiant_s etudiant;
    FILE *fp;

    fp = fileops(file, "r");
    lines = countlines(fp);
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%d %s %s %s %s %f", &etudiant.uniqueId,
               etudiant.nom,
               etudiant.prenom,
               etudiant.naissance,
               etudiant.departement,
               &etudiant.note);

        total += etudiant.note;
    }

    return (total / lines);
}

float moyennePardeptment(char departement[])
{
}
void statsMenu()
{
    int choix, select, total;
    char *departments[] = {INFO, MECH, RH, JUR};
    printf("1: afficher le nombre total des etudiant\n");
    printf("2: afficher le nombre des etudiant sur un departement\n");
    printf("3: la moyenne General de l'universite\n");
    printf("4: la moyene General d'une departement\n");
    printf("5: afficher les etudients ayant le moyene general sup d'un seuil\n");
    printf("6: afficher les 3 etudiants ayant la meilleur notes\n");
    printf("7: afficher le nombre des etudiant reussite\n");
    printf("0: retour to menu Pricipal\n");
    printf("Enter Votre choix: ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        total = totaletudiant();
        printf("le Total nombre des Eutidiant est: %d \n", total);
    }
    else if (choix == 2)
    {
        printf("Enter un departement:\n(1): informatique\n(2): mechanique\n(3): resource_humaine\n(4): juridique\nChoisir: ");
        scanf("%d", &select);
        printf("le nombre des etudiant sur %s departement est %d \n", departments[select - 1], totalBydeprtement(departments[select - 1]));
    }
    else if (choix == 3)
    {
        printf("le moyenne General de l'universite est %.2f\n", moyenneGlobal());
    }
    else if (choix == 4)
    {
    }
    /*else if (choix == 5)
    {
    } else if (choix == 6) {

    } else if (choix == 7) {

    }*/
}