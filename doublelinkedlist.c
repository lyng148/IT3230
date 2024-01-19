#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *Makenode(int x)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->data = x;
    Newnode->next = NULL;
    Newnode->prev = NULL;
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

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void pushfront(node **head, int x)
{
    node *Newnode = Makenode(x);
    Newnode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = Newnode;
    }
    *head = Newnode;
}

void pushback(node **head, int x)
{
    node *Newnode = Makenode(x);
    if (*head == NULL)
        pushfront(head, x);
    else
    {
        node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = Newnode;
        Newnode->prev = tmp;
    }
}

void insert(node **head, int k, int x)
{
    node *Newnode = Makenode(x);
    if (k == 1)
        pushfront(head, x);
    else if (k == size(*head) + 1)
        pushback(head, x);
    else
    {
        node *tmp = *head;
        int i = 1;
        while (i < k - 1)
        {
            tmp = tmp->next;
            i++;
        }
        Newnode->next = tmp->next;
        tmp->next->prev = Newnode;
        tmp->next = Newnode;
        Newnode->prev = tmp;
    }
}

void popfront(node **head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    if ((*head)->next != NULL)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    else
    {
        *head = NULL;
    }

    free(tmp);
}

void popback(node **head)
{
    if (head == NULL)
        return;
    else
    {
        node *tmp = *head;
        if (tmp->next == NULL)
            popfront(head);
        else
        {
            while (tmp->next->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = NULL;
        }
    }
}

void erase(node **head, int k)
{
    if (k == 1)
        popfront(head);
    else if (k == size(*head))
        popback(head);
    else
    {
        node *tmp = *head;
        int i = 1;
        while (i < k - 1)
        {
            tmp = tmp->next;
        }
        node *tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        tmp->next->prev = tmp;
        free(tmp2);
    }
}

void reverse(node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    node *tmp = *head;
    node *prev = tmp->prev;
    node *next = tmp->next;

    while (tmp != NULL)
    {
        next = tmp->next;
        prev = tmp->prev;
        tmp->prev = next;
        tmp->next = prev;
        tmp = next;
    }
    *head = prev->prev;
}

bool check_duplicate(node *head, int x)
{
    while (head != NULL)
    {
        if (head->data == x)
        {
            return true;
        }
        else
            head = head->next;
    }
    return false;
}

int main()
{
    node *head = NULL;
    pushback(&head, 1);
    pushback(&head, 2);
    duyet(head);
}

