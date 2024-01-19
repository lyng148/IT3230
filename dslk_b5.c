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
    node *Newnode = (node *)malloc(sizeof(node)); // cap phat 1 node
    Newnode->data = x;
    Newnode->next = NULL;
    return Newnode; // tra ve con tro den node moi
}

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

void insert(node **head, int k, int x)
{
    if (k == 1)
        pushfront(head, x);
    else if (k == size(*head) + 1)
        pushback(head, x);
    else
    {
        node *Newnode = Makenode(x);
        int i = 1;
        node *temp = *head;
        while (i != k - 1)
        {
            i++;
            temp = temp->next;
        }
        Newnode->next = temp->next;
        temp->next = Newnode;
    }
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
        while (i < k - 1){
            i++;
            tmp2 = tmp2->next;
        }
        node* tmp = tmp2 -> next;
        tmp2->next = tmp2->next->next;
        free(tmp);
    }
}

void sort_increae(node **head){
    for (node* i = *head; i != NULL; i = i ->next){
        for (node* j = i; j != NULL;j = j ->next){
            if (i->data >  j->data){
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void sort_decreae(node **head){
    for (node* i = *head; i != NULL; i = i ->next){
        for (node* j = i; j != NULL;j = j ->next){
            if (i->data <  j->data){
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

int main()
{
    node *head = NULL;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        pushback(&head, k);
    }
    sort_increae(&head);
    duyet(head);
    sort_decreae(&head);
    duyet(head);
}