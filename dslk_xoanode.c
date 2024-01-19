#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *Makenode(int x)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->data = x;
    Newnode->next = NULL;
    return Newnode;
}

void duyet(node *head)
{
    if (head == NULL)
        printf("EMPTY");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void pushfront(node **head, int x)
{
    node *Newnode = Makenode(x);
    Newnode->next = (*head);
    (*head) = Newnode;
}

void pushback(node **head, int x)
{
    node *Newnode = Makenode(x);
    if (*head == NULL)
    {
        *head = Newnode;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = Newnode;
    return;
}

void removehead(node **head)
{
    node *tmp = *head;
    (*head) = (*head)->next;
    free(tmp);
}

void removetail(node *head)
{
    if (head == NULL)
        return;
    int i = 1;
    while (i <= size(head))
    {
        i++;
        head = (head)->next;
    }
    node *tmp = head->next;
    head->next = NULL;
    free(tmp);
}

void removemid(node **head, int k)
{
    if (k == 1)
        removehead(head);
    else if (k == size(*head))
        removetail(*head);
    else
    {
        node *tmp2 = *head;
        int i = 1;
        while (i < k - 1)
        {
            i++;
            tmp2 = tmp2->next;
        }
        node *tmp = tmp2->next;
        tmp2->next = tmp2->next->next;
        free(tmp);
    }
}
void xoa(node **head, int x)
{
    node *current = *head;
    node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == x)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
            else
            {
                *head = current->next;
                free(current);
                current = *head;
            }
        }
        else{
            prev = current;/*  */
            current = current->next;
        }
    }
}

int main()
{
    node *head = NULL;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d ", &a);
        pushback(&head, a);
    }
    xoa(&head, k);
    duyet(head);
}