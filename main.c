#include "main.h"

int main()
{
    int choix, select;
    char *departments[] = {INFO, MECH, RH, JUR};
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
            if (scanf("%d", &select) != 1)
            {
                clear_buffer();
                continue;
            }
            if (select <= 0)
            {
                printf("Selection incorrect\n");
                clear_buffer();
                continue;
            }
            ajouteEtudiant(departments[select - 1]);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            // statistique sous Menu
            break;
        case 6:
            // recherche sous-Menu
            break;
        case 7:
            // tri sous-Menu
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