#include "main.h"


void triHightoLow(Etudiant_s etudiants[], int lines) {
    int i, j;
    Etudiant_s temp;
    for(i = 0; i < lines; i++) {
        for (j = 0; j < lines - i - 1; j++) {
            if(etudiants[j].note < etudiants[j + 1].note) {
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
    printArray(etudiants, lines);
}

void triLowtoHigh(Etudiant_s etudiants[], int lines) {
    int i, j, k;
    Etudiant_s temp;
    for(i = 0; i < lines; i++) {
        for (j = 0; j < lines - i - 1; j++) {
            if(etudiants[j].note > etudiants[j + 1].note) {
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
    printArray(etudiants, lines);
}

void triAaZ(Etudiant_s etudiants[], int lines) {
    int i, j, k;
    Etudiant_s temp;
    for (i = 0; i < lines; i++) {
        for (j = 0; j < lines - i - 1; j++) {
            if(strcmp(etudiants[j].nom, etudiants[j + 1].nom) > 0) {
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
    printArray(etudiants, lines);
}

void triZaA(Etudiant_s etudiants[],  int lines) {
    int i, j, k;
    Etudiant_s temp;
    printf("%s %s\n", etudiants[1].nom, etudiants[1].prenom);
    for (i = 0; i < lines; i++) {
        for (j = 0; j < lines - i - 1; j++) {
            if(strcmp(etudiants[j].nom, etudiants[j + 1].nom) < 0) {
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
    printArray(etudiants, lines);
}

void triparstatus(Etudiant_s etudiants[], int lines) {
    int i, j;
    float seuil = 10.00;
    
    printf("Etudiant Reussite: \n");
    for (i = 0; i < lines; i++) {
      if( etudiants[i].note >= seuil) {
        printf("%d %s %s %s %s %.2f\n", etudiants[i].uniqueId,
                                        etudiants[i].nom,
                                        etudiants[i].prenom,
                                        etudiants[i].naissance,
                                        etudiants[i].departement,
                                        etudiants[i].note);
      }  
    }
    printf("=================================================");
    printf("\n");
    printf("Etudiant non Reussite: \n");
    for(j = 0; j < lines; j++) {
      if( etudiants[j].note <= seuil) {
        printf("%d %s %s %s %s %.2f\n", etudiants[j].uniqueId,
                                        etudiants[j].nom,
                                        etudiants[j].prenom,
                                        etudiants[j].naissance,
                                        etudiants[j].departement,
                                        etudiants[j].note);
      }  
    }
}


void triMenu() {
    char buffer[MAX];
    int select, lines, i = 0;
    FILE *fp;

    fp = fileops(file, "r");
    lines = countlines(fp);

    Etudiant_s *etudiants = malloc(sizeof(Etudiant_s) * lines);

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %s %s %s %f", &etudiants[i].uniqueId,
                                            etudiants[i].nom,
                                            etudiants[i].prenom,
                                            etudiants[i].naissance,
                                            etudiants[i].departement,
                                            &etudiants[i].note);
                                            i++;
        
    }
    printf("1: tri de A-Z\n");
    printf("2: tri de Z-A\n");
    printf("3: tri par note plus eleve a plus faible\n");
    printf("4: tri par note plus faible a plus elevee\n");
    printf("5: tri etudiant qui ont reussite ( egale ou sup a 10/20)\n");
    printf("0: retourn aux menu Principal\n");
    printf("Enter Votre Selection: ");
    scanf("%d", &select);

    if(select == 1) {
        triAaZ(etudiants, lines);
    }
    else if (select == 2) {
        triZaA(etudiants, lines);
    } else if (select == 3) {
        triHightoLow(etudiants, lines);
    } else if (select == 4) {
        triLowtoHigh(etudiants, lines);
    } else if (select == 5) {
        triparstatus(etudiants, lines);
    }
    fclose(fp);
    free(etudiants);
}