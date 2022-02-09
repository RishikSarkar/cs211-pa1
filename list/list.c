#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* current = NULL;

void printList()
{
    struct Node* ptr1 = head;

    int n = 0;

    while (ptr1 != NULL)
    {
        n++;
        ptr1 = ptr1->next;
    }

    printf("%d :", n);

    if (n > 0)
    {
        printf(" ");
    }

    struct Node* ptr2 = head;
    int c = 0;

    while (ptr2 != NULL)
    {
        printf("%d", ptr2->data);
        if (c < n - 1)
        {
            printf(" ");
        }
        ptr2 = ptr2->next;
        c++;
    }

    //printf("%d", ptr2->next->data);

    printf("\n");
}

void insert (int n)
{
    struct Node* current = head;
    struct Node* previous = NULL;

    if (head == NULL)
    {
        struct Node *first = (struct Node*) malloc(sizeof(struct Node));
        first->data = n;
        head = first;
        head->next = NULL;
        return;
    }    

    while (current->data != n)
    {
        if (current->next == NULL)
        {
            if (previous == NULL)
            {
                if (current->data > n)
                {
                    struct Node *first = (struct Node*) malloc(sizeof(struct Node));
                    first->data = n;
                    head = first;
                    head->next = current;
                    return;
                }
                else
                {
                    struct Node *last = (struct Node*) malloc(sizeof(struct Node));
                    last->data = n;
                    head->next = last;
                    last->next = NULL;
                    return;
                }
            }
            else
            {
                if (current->data > n)
                {
                    struct Node *link = (struct Node*) malloc(sizeof(struct Node));
                    link->data = n;
                    previous->next = link;
                    link->next = current;
                    return;
                }
                else
                {
                    struct Node *last = (struct Node*) malloc(sizeof(struct Node));
                    last->data = n;
                    current->next = last;
                    last->next = NULL;
                    return;
                }
            }
        }

        if (current->data > n)
        {
            if (previous == NULL)
            {
                struct Node *first = (struct Node*) malloc(sizeof(struct Node));
                first->data = n;
                head = first;
                head->next = current;
                return;
            }
            else
            {
                struct Node *link = (struct Node*) malloc(sizeof(struct Node));
                link->data = n;

                previous->next = link;
                link->next = current;

                return;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    return;
}

void delete (int n)
{
    struct Node* current = head;
    struct Node* previous = NULL;

    if (head == NULL)
    {
        return;
    }

    while (current->data != n)
    {
        if (current->next == NULL)
        {
            return;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (current == head)
    {
        head = head->next;
        free(current);
    }
    else
    {
        previous->next = current->next;
        free(current);
    }

    return;
}

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        FILE *fp = fopen(argv[1], "r");

        char entry[100];

        if (!fp)
        {
            exit(EXIT_FAILURE);
            return 0;
        }

        while (fgets(entry, sizeof(entry), fp))
        {
            char c = ' ';
            int n = -1;

            sscanf(entry, "%c %d", &c, &n);

            if (c == 'i')
            {
                insert(n);
            }
            else
            {
                delete(n);
            }
            if (c != '\n')
                printList();
        }
    }
    else
    {
        /*insert(5); printList();
        delete(3); printList();
        insert(3); printList();
        insert(500); printList();
        delete(5); printList();*/

        while (!feof(stdin))
        {
            char c = ' ';
            int n = -1;

            scanf("%c %d", &c, &n);

            if (c == 'i')
            {
                insert(n);
            }
            else
            {
                delete(n);
            }
            if (c != '\n')
                printList();
        }
    }

    return 0;
}
