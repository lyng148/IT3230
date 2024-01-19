#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *Makenode(int data)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->data = data;
    Newnode->next = NULL;
    return Newnode;
}

void pushback(node **head, int x)
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

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int k;
    node *head = NULL;
    while (scanf("%d", &k) != EOF)
    {
        pushback(&head, k);
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL)
    {
        if (fast->data != slow->data)
        {
            slow = slow->next;
            slow->data = fast->data;
            fast = fast->next;
        }
        else
            fast = fast->next;
    }
    slow->next = NULL;

    duyet(head);
    return 0;
}