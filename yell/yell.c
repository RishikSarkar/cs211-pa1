#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) 
{
    if (argc == 1 || *argv[1] == '\0')
    {
        return 0;
    }

    for (int n = 1; n < argc; n++)
    {
        for (int i = 0; argv[n][i] != '\0'; i++)
        {
            printf("%c", toupper(argv[n][i]));
        }

        if (n + 1 != argc)
        {
            printf(" ");
        }
    }

    printf("!!\n");

    return 0;
}
