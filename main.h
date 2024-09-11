#ifndef MAIN_H
#define MAIN_H

#define MAX 1024

#define file "students.txt"
#define INFO "informatique"
#define MECH "mechanique"
#define RH "resource_humain"
#define JUR "juridique"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct etudiant
{
	int uniqueId;
	char nom[MAX];
	char prenom[MAX];
	char naissance[MAX];
	char departement[MAX];
	float note;
} Etudiant_s;

void ajouteEtudiant(char departemet[]);
void affichertous();
void modification(int id, Etudiant_s temp);
void removeEtudiant(int id);

void statsMenu();
int totaletudiant();
void totalParDep();
float moyenneGlobal();
float etudiantParseuil(float seuil);

void rechercheOps(int choix);
int searchBydeprtement(char departement[]);
void searchByname(char name[]);

FILE *fileops(char filename[], char mode[]);

int countlines(FILE *fp);
void Welcome();
void clear_buffer();

#endif
