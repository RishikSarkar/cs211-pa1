#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* root = NULL;
struct Node* parent = NULL;

struct Node* createNode(int n)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(struct Node* r, struct Node* p, int n)
{
    if (r == NULL)
    {
        r = createNode(n);
        if (p == NULL)
        {
            root = r;
        }
        printf("inserted\n");
        return;
    }
    if (n == r->data)
    {
        printf("not inserted\n");
        return;
    }
    else if (n > r->data)
    {
        if (r->right == NULL)
        {
            r->right = createNode(n);
            printf("inserted\n");
            return;
        }
        else
        {
            insert(r->right, r, n);
            return;
        }
    }
    else if (n < r->data)
    {
        if (r->left == NULL)
        {
            r->left = createNode(n);
            printf("inserted\n");
            return;
        }
        else
        {
            insert(r->left, r, n);
            return;
        }
    }

    return;
}

void search(struct Node* r, int n)
{
    if (r == NULL)
    {
        printf("absent\n");
        return;
    }
    if (n == r->data)
    {
        printf("present\n");
        return;
    }
    else if (n > r->data)
    {
        if (r->right == NULL)
        {
            printf("absent\n");
            return;
        }
        else
        {
            search(r->right, n);
            return;        }
    }
    else if (n < r->data)
    {
        if (r->left == NULL)
        {
            printf("absent\n");
            return;
        }
        else
        {
            search(r->left, n);
            return;
        }
    }

    return;
}

void print(struct Node* r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        char *num = malloc(20 * sizeof(char));
        sprintf(num, "%d", r->data);

        printf("(");
        print(r->left);
        printf("%s", num);
        print(r->right);
        printf(")");

        free(num);
        return;
    }

    return;
}

/*void freeMemory(struct Node* r)
{
    if (r == NULL)
    {
        free(r);
        return;
    }
    else
    {
        freeMemory(r->left);
        freeMemory(r->right);
        freeMemory(r);
        return;
    }
    return;
}*/

void delete(struct Node* p, struct Node* r, int n)
{
    if (r == NULL)
    {
        printf("absent\n");
        return;
    }

    if (r->data == n)
    {
        if (r->left == NULL && r->right == NULL)
        {
            if (p == NULL)
            {
                free(r);
                root = NULL;
                printf("deleted\n");
                return;
            }
            if (r->data < p->data)
            {
                free(p->left);
                p->left = NULL;
                printf("deleted\n");
                return;
            }
            else
            {
                free(p->right);
                p->right = NULL;
                printf("deleted\n");
                return;
            }
        }
        if (r->left != NULL)
        {
            struct Node* c;
            struct Node* temp = NULL;

            for (c = r->left; c->right != NULL; c = c->right)
            {
                temp = c;
            }

            if (temp != NULL)
            {
                r->data = temp->right->data;
                delete(temp, temp->right, temp->right->data);
            }
            else
            {
                int x = r->left->data;
                delete(r, r->left, r->left->data);
                r->data = x;
            }
            
            return;
        }
        else if (r->right != NULL)
        {
            struct Node* temp = r->right;
            r->data = r->right->data;
            r->left = r->right->left;
            r->right = r->right->right;
            free(temp);
            printf("deleted\n");
            return;
        }
    }
    else if (r->data > n)
    {
        delete(r, r->left, n);
        return;
    }
    else
    {
        delete(r, r->right, n);
        return;
    }
    return;
}

int main(int argc, char **argv)
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

            sscanf(entry, "%c", &c);

            if (c == 'p')
            {
                if (c != '\n')
                {
                    print(root);
                    printf("\n");
                    continue;
                }
            }
            else
            {
                sscanf(entry, " %d", &n);

                if (c == 'i')
                {
                    insert(root, parent, n);
                    //print(root);
                    //printf("\n");
                }
                else if (c == 's')
                {
                    search(root, n);
                }
                else if (c == 'd')
                {
                    delete(parent, root, n);
                }
                /*else if (c == 'p')
                {
                    if (c != '\n')
                    {
                        print(root);
                        printf("\n");
                    }
                }*/
            }

            /*if (c == 'i')
            {
                insert(root, parent, n);
            }
            else if (c == 's')
            {
                search(root, n);
            }
            else if (c == 'p')
            {
                if (c != '\n')
                {
                    print(root);
                    printf("\n");
                }
            }*/
        }
    }
    else
    {
        while (!feof(stdin))
        {
            char c = ' ';
            int n = -1;

            scanf("%c", &c);

            if (c == 'p')
            {
                if (c != '\n')
                {
                    print(root);
                    printf("\n");
                    continue;
                }
            }
            else
            {
                scanf(" %d", &n);

                if (c == 'i')
                {
                    insert(root, parent, n);
                    //print(root);
                    //printf("\n");
                }
                else if (c == 's')
                {
                    search(root, n);
                }
                else if (c == 'd')
                {
                    delete(parent, root, n);
                }
                /*else if (c == 'p')
                {
                    if (c != '\n')
                    {
                        print(root);
                        printf("\n");
                    }
                }*/
            }
        }
    }

    //free(root);
    return 0;
}