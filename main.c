#include "main.h"

int main()
{
    int choix, c;
    do
    {
        Welcome();
        printf("Enter your choice: ");
        if (scanf("%d", &choix) != 1)
        {
            printf("Invalid input\n");
            while ((c = getchar()) != '\n')
                ;
            continue;
        }

        switch (choix)
        {
        case 1:
            printf("%d\n", choix);
            printf("Test Here\n");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
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