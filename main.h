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
	// char departement[MAX];
	int note;
} Etudiant_s;

void ajouteEtudiant();
FILE *fileops(char filename[], char mode[]);

int countlines(FILE *fp);
void Welcome();

#endif
