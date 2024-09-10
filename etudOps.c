#include "main.h"

void ajouteEtudiant()
{
    char buffer[MAX];
    int lines;
    Etudiant_s etudiant;
    FILE *fp;

    fp = fileops(file, "a");
    lines = countlines(fp);
    getchar();
    printf("Enter le nom, le prenom, la date de naissance et la note(separe par espace)");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        etudiant.uniqueId = lines + 1;
        // strcpy(etudiant.departement, depart);
        sscanf(buffer, "%s %s %s %d", etudiant.nom, etudiant.prenom, etudiant.naissance, &etudiant.note);
    }
    fprintf(fp, "%d %s %s %s %d", etudiant.uniqueId,
            etudiant.nom,
            etudiant.prenom,
            etudiant.naissance,
            /*etudiant.departement*/
            etudiant.note);
    fclose(fp);
}