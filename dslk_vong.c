#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    bool head;
    bool checked;
    struct node *next;
    struct node *prev;
} node;

node *Makenode(int x)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->data = x;
    Newnode->head = false;
    Newnode->checked = false;
    Newnode->next = NULL;
    Newnode->prev = NULL;
    return Newnode;
}

void pushback(node **head, int x)
{
    node *Newnode = Makenode(x);
    if (*head == NULL)
    {
        *head = Newnode;
        (*head)->head = true;
        (*head)->next = *head; 
        (*head)->prev = *head; 
        return;
    }
    else
    {
        node *tmp = *head;
        while (tmp->next->head == false)
        {  
            tmp = tmp->next;
        }
        Newnode->next = tmp->next;
        tmp->next->prev = Newnode;
        Newnode->prev = tmp;
        tmp->next = Newnode;
    }
}

void duyet(node *head, int x)
{
    int i = 0;
    while (i < x)
    {
        head = head->next;
        i++;
    }
     while (head->checked == false)
    {
        printf("%d ", head->data);
        head->checked = true;
        head = head->next;
    }  
}

int main()
{
    node *head = NULL;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int k; scanf("%d", &k);
        pushback(&head, k);
    }
    int k; scanf("%d", &k);
    duyet(head, k);
    return 0;
}
