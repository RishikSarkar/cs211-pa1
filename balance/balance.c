#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char pop(char *c)
{
    if (*c == '\0')
    {
        return ' ';
    }

    int i = 0;

    while (c[i] != '\0')
    {
        i++;
    }

    char top = c[i - 1];
    c[i - 1] = '\0';

    return top;
}

/*void push(char delim, char *c)
{
    if (c[0] == '\0')
    {
        c[0] = delim;
        c[1] = '\0';
        return;
    }

    int i = 0;

    while (c[i] != '\0')
    {
        i++;
    }

    c[i] = delim;
    c[i++] = '\0';
    return;
}*/

int compare(char d1, char d2)
{
    if (d1 == '(')
    {
        if (d2 == ')')
            return 1;
        else
            return 0;
    }

    if (d1 == '{')
    {
        if (d2 == '}')
            return 1;
        else
            return 0;
    }

    if (d1 == '[')
    {
        if (d2 == ']')
            return 1;
        else
            return 0;
    }

    return 0;
}

char reverse(char c)
{
    switch(c)
    {
        case '(':
            return ')';
            break;
        case '{':
            return '}';
            break;
        case '[':
            return ']';
            break;
        default:
            return ' ';
    }
}

void printreverse(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    for (int c = i - 1; c >= 0; c--)
    {
        printf("%c", reverse(s[c]));
    }

    return;
}

int main(int argc, char **argv)
{
    if (argc == 1 || *argv[1] == '\0')
    {
        exit(EXIT_FAILURE);
        return 0;
    }

    //printf("%s\n", argv[1]);

    int length = strlen(argv[1]);

    char *stack = malloc((length + 1) * sizeof(char));

    stack[0] = '\0';

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] == '(' || argv[1][i] == '{' || argv[1][i] == '[')
        {
            int n = 0;
            while (stack[n] != '\0')
                n++;
            stack[n] = argv[1][i];
            stack[n + 1] = '\0';
        }
        else if (argv[1][i] == ')' || argv[1][i] == '}' || argv[1][i] == ']')
        {
            if (compare(pop(stack), argv[1][i]) == 0)
            {
                printf("%d: %c\n", i, argv[1][i]);
                free(stack);
                exit(EXIT_FAILURE);
                return 0;
            }
        }
    }

    if (stack[0] != '\0')
    {
        printf("open: ");
        printreverse(stack);
        printf("\n");

        free(stack);
        exit(EXIT_FAILURE);
        return 0;
    }

    /*char test[10] = {'1', '9', '(', 'a'};

    push('&', test);

    printf("%s\n", test);

    printf("%c\n", pop(test));*/

    free(stack);

    exit(EXIT_SUCCESS);
    return 0;
}