#include "main.h"

int main()
{
    int choix, select, id;
    char *departments[] = {INFO, MECH, RH, JUR};
    Etudiant_s temp;
    do
    {
        Welcome();
        printf("Enter your choice: ");
        if (scanf("%d", &choix) != 1)
        {
            clear_buffer();
            continue;
        }

        switch (choix)
        {
        case 1:
            printf("1: informatique\n");
            printf("2: mechanique\n");
            printf("3: resource humaine\n");
            printf("4: juridique\n");
            printf("Enter votre Selection: ");
            scanf("%d", &select);
            ajouteEtudiant(departments[select - 1]);
            break;
        case 2:
            affichertous();
            break;
        case 3:
            affichertous();
            printf("Quel etudiant vous voulez modifie? ( Entree le id)");
            scanf("%d", &id);
            printf("Entre le nouveau Nom: ");
            scanf("%s", temp.nom);
            printf("Entre le nouveau prenom: ");
            scanf("%s", temp.prenom);
            printf("Entre la nouveau note: ");
            scanf("%f", &temp.note);
            printf("Entre la nouveau date de naissance: ");
            scanf("%s", temp.naissance);
            printf("Entree la nouveau departement:\n(1): informatique\n(2): mechanique\n(3): resource_humaine\n(4): juridique\nChoisir: ");
            scanf("%d", &choix);
            strcpy(temp.departement, departments[choix - 1]);
            modification(id, temp);
            affichertous();
            break;
        case 4:
            affichertous();
            printf("Quel letudiant que vous voulez supprimer: ");
            scanf("%d", &id);
            removeEtudiant(id);
            affichertous();
            break;
        case 5:
            printf("1: recherche par nom d'etudiant(s)\n2: recherche par departement\n");
            printf("Entree Votre choix: ");
            scanf("%d", &choix);
            rechercheOps(choix);
            break;
        case 6:
            triMenu();
            break;
        case 7:
            statsMenu();
            break;
        case 0:
            printf("Quitting.....\n");
            exit(0);
        default:
            printf("Please Select From the Menu Choices\n");
            break;
        }

    } while (1);

    return (0);
}