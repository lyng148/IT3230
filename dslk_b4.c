

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *Makenode(int x)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->data = x;
    Newnode->next = NULL;
    return Newnode;
}

int size(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void push(node **head, int x)
{
    node *Newnode = Makenode(x);
    if (*head == NULL)
    {
        *head = Newnode;
        return;
    }
    else
    {
        node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = Newnode;
    }
}

void pop(node **head)
{
    if (*head == NULL)
        return;
    else
    {
        node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

void front(node **head)
{
    if (*head == NULL)
        printf("EMPTY\n");
    else
        printf("%d\n", (*head)->data);
}

int main()
{
    node *head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[10];
        scanf("%s", s);
        if (strcmp(s, "push") == 0)
        {
            int k;
            scanf("%d", &k);
            push(&head, k);
        }
        else if (strcmp(s, "pop") == 0)
            pop(&head);
        else if (strcmp(s, "front") == 0)
            front(&head);
    }
}