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
    printf("lines now are: %d\n", lines);
    getchar();
    etudiant.uniqueId = lines + 1;
    printf("Enter le nom, le prenom, la date de naissance et la note(separe par espace): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        strcpy(etudiant.departement, departemet);
        sscanf(buffer, "%s %s %s %f", etudiant.nom, etudiant.prenom, etudiant.naissance, &etudiant.note);
    }
    fprintf(fp, "\n%d %s %s %s %s %.2f", etudiant.uniqueId,
            etudiant.nom,
            etudiant.prenom,
            etudiant.naissance,
            etudiant.departement,
            etudiant.note);
    fclose(fp);
    fclose(tfp);
}