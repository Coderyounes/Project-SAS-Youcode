#include "main.h"

void ajouteEtudiant(char departemet[])
{
    char buffer[MAX];
    int lines;
    Etudiant_s etudiant;
    FILE *fp, *tfp;

    fp = fileops(file, "a");
    tfp = fileops(file, "r");
    lines = countlines(tfp);

    getchar();

    etudiant.uniqueId = lines + 1;
    printf("Enter le nom, le prenom, la date de naissance et la note(separe par espace): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        strcpy(etudiant.departement, departemet);
        sscanf(buffer, "%s %s %s %f", etudiant.nom, etudiant.prenom, etudiant.naissance, &etudiant.note);
    }
    fprintf(fp, "%d %s %s %s %s %.2f\n", etudiant.uniqueId,
            etudiant.nom,
            etudiant.prenom,
            etudiant.naissance,
            etudiant.departement,
            etudiant.note);
    fclose(fp);
    fclose(tfp);
}

void affichertous()
{
    char buffer[MAX];
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

        printf("%d %s %s %s %s %.2f\n", etudiant.uniqueId,
               etudiant.nom,
               etudiant.prenom,
               etudiant.naissance,
               etudiant.departement,
               etudiant.note);
    }
    fclose(fp);
}

void modification(int id)
{
}