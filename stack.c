#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

node *Makenode(char x)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->data = x;
    Newnode->next = NULL;
    return Newnode;
}

char pop(node **head)
{
    if (*head == NULL)
        return 0;
    else
    {
        char k = (*head)->data;
        node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return k;
    }
}

char top(node **head)
{
    return (*head)->data;
}

void push(node **head, char x)
{
    node *Newnode = Makenode(x);
    if (*head == NULL)
        *head = Newnode;
    else
    {
        Newnode->next = (*head);
        (*head) = Newnode;
    }
}

bool empty(node **head)
{
    return *head == NULL;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        head = head->next;
    }
}

int main()
{
    char nho = 0;
    node *a = NULL;
    node *b = NULL;
    node *kq = NULL;
    char a1[1000];
    char a2[1000];
    fgets(a1, sizeof(a1), stdin);
    fgets(a2, sizeof(a2), stdin);
    a1[strlen(a1) - 1] = '\0';
    a2[strlen(a2) - 1] = '\0';
    for (int i = 0; i < strlen(a1); i++)
    {
        push(&a, a1[i] - '0');
    }
    for (int i = 0; i < strlen(a2); i++)
    {
        push(&b, a2[i] - '0');
    }
    while (!empty(&a) && !empty(&b))
    {
        char a_ = pop(&a);
        char b_ = pop(&b);
        if (a_ + b_ + nho >= 10)
        {
            push(&kq, a_ + b_ + nho - 10);
            nho = 1;
        }
        else
        {
            if (a_ + b_ + nho < 10)
            {
                push(&kq, a_ + b_ + nho);
                nho = 0;
            }
        }
    }
    if (a != NULL && nho == 0)
    {
        while (a != NULL)
        {
            int k = pop(&a);
            push(&kq, k);
        }
    }
    else if (a != NULL && nho == 1)
    {
        int k = pop(&a);
        push(&kq, k + 1);
        while (a != NULL)
        {
            int k = pop(&a);
            push(&kq, k);
        }
    }

    if (b != NULL && nho == 0)
    {
        while (b != NULL)
        {
            int k = pop(&b);
            push(&kq, k);
        }
    }
    else if (b != NULL && nho == 1)
    {
        int k = pop(&b);
        push(&kq, k + 1);
        while (b != NULL)
        {
            int k = pop(&b);
            push(&kq, k);
        }
    }
    
    duyet(kq);
}
