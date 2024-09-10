#include "main.h"

FILE *fileops(char filename[], char mode[])
{
    FILE *fp;

    fp = fopen(filename, mode);
    if (!fp)
    {
        return (NULL);
    }
    return fp;
}