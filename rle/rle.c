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

    char *argument = argv[1];

    int arglen = strlen(argument);
    int flen = 2 * arglen;

    char *final;
    final = malloc((flen + 1) * sizeof(char));

    if (argument[0] == '\0')
    {
        free(final);
        return 0;
    }

    int current = 0;
    int next;
    int count = 1;
    int index = 0;

    for (current = 0; current < arglen;)
    {
        if (argument[current] >= '0' && argument[current] <= '9')
        {
            printf("error");
            free(final);
            return 0;
        }

        for (next = current + 1; next < arglen; next++)
        {
            if (argument[next] != argument[current])
            {
                break;
            }
            count++;
        }

        int r = (flen + 1) - index;
        int size = snprintf(final + index, r, "%c%d", argument[current], count);
        index += size;

        if (index > arglen)
        {
            printf("%s\n", argument);

            free(final);

            return 0;
            /*final = argument;
            break;*/
        }

        current += count;
        count = 1;

        /*if (argument[next] == argument[current])
        {
            count++;
        }
        else
        {
            //final[strlen(final) + 1] = argument[current];
            sprintf(final, "%c", count);
            count = 1;
        }*/
    }

    //final[arglen] = '\0';

    printf("%s\n", final);

    free(final);

    return 0;
}