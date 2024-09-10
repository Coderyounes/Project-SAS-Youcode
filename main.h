#ifndef MAIN_H
#define MAIN_H

#define MAX 1024
#define INFO "informatique"
#define MECH "mechanique"
#define RH "resource_humain"
#define JUR "juridique"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct etudiant
{
	int uniqueId;
	char nom[MAX];
	char prenom[MAX];
	char naissance[MAX];
	char departement;
	int note;
} Etudiant_s;

FILE *fileops(char filename[], char mode[]);

void Welcome();

#endif
