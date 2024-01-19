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

void show(node *head)
{

    if (head == NULL)
    {
        printf("EMPTY\n\n");
        return;
    }
    int k = size(head);
    int a[k];
    int i = 0;
    while (head != NULL)
    {
        a[i++] = head->data;
        head = head->next;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
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
    node *tmp = *head;
    if (tmp->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
}

int main()
{
    node *head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[12];
        scanf("%s", s);
        if (strcmp(s, "pop") == 0)
            pop(&head);
        else if (strcmp(s, "show") == 0)
            show(head);
        else if (strcmp(s, "push") == 0)
        {
            int k;
            scanf("%d", &k);
            push(&head, k);
        }
    }
}