#include "main.h"

int totaletudiant()
{
    FILE *fp;
    int count;

    fp = fileops(file, "r");
    count = countlines(fp);

    return count;
}

void totalParDep() {
    char buffer[MAX];
    int info = 0, mech = 0, rh = 0, jur = 0;
    Etudiant_s etudiant;
    FILE *fp;

    fp = fileops(file, "r");

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %s %s %s %d", &etudiant.uniqueId,
                                            etudiant.nom,
                                            etudiant.prenom,
                                            etudiant.naissance,
                                            etudiant.departement,
                                            &etudiant.note);
        if(strcmp(etudiant.departement, INFO)) {
            info++;
        } else if (strcmp(etudiant.departement, MECH)) {
            mech++;
        } else if (strcmp(etudiant.departement, RH)) {
            rh++;
        } else if (strcmp(etudiant.departement, JUR)) {
            jur++;
        }
    }
    printf("Number des etudiant Pour la departement %s est %d\n", INFO, info);
    printf("Number des etudiant Pour la departement %s est %d\n", MECH, mech);
    printf("Number des etudiant Pour la departement %s est %d\n", RH, rh);
    printf("Number des etudiant Pour la departement %s est %d\n", JUR, jur);

    fclose(fp);

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
    char buffer[MAX];
    float total = 0, count = 0;
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
        if (strcmp(etudiant.departement, departement) == 0)
        {
            total += etudiant.note;
            count++;
        }
    }

    return (total / count);
}

float noteParseuil(char departement[]) {

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
        totalParDep();
    }
    else if (choix == 3)
    {
        printf("le moyenne General de l'universite est %.2f\n", moyenneGlobal());
    }
    else if (choix == 4)
    {
        printf("Enter un departement:\n(1): informatique\n(2): mechanique\n(3): resource_humaine\n(4): juridique\nChoisir: ");
        scanf("%d", &select);
        printf("la moyenne General de departement %s est %.2f\n", departments[select - 1], moyennePardeptment(departments[select - 1]));
    }
    else if (choix == 5)
    {
        // affichage des etudiant ayant u
    } /*else if (choix == 6) {

    } else if (choix == 7) {

    }*/
}