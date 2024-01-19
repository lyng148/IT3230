#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[1000];
    float grade;
    struct node *next;
    struct node *prev;
} node;

node *Makenode(char *x, float grade)
{
    node *Newnode = (node *)malloc(sizeof(node));
    strcpy(Newnode->data, x);
    Newnode->grade = grade;
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
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void swapNode(node* a, node* b) {
    float tempGrade = a->grade;
    a->grade = b->grade;
    b->grade = tempGrade;
    char tempName[1000];
    strcpy(tempName, a->data);
    strcpy(a->data, b->data);
    strcpy(b->data, tempName); 
}

void pushfront(node **head, char *x, float grade)
{
    node *Newnode = Makenode(x, grade);
    Newnode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = Newnode;
    }
    *head = Newnode;
}

void pushback(node **head, char *x, float grade)
{
    node *Newnode = Makenode(x, grade);
    if (*head == NULL)
        pushfront(head, x, grade);
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

void insert(node **head, int k, char *x, float grade)
{
    node *Newnode = Makenode(x, grade);
    if (k == 1)
        pushfront(head, x, grade);
    else if (k == size(*head) + 1)
        pushback(head, x, grade);
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

void selectionSort(node *head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        node *min = i;
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (j->grade < min->grade)
            {
                min = j;
            }
        }

        char tmp[1000];
        strcpy(tmp, min->data);
        strcpy(min->data, i->data);
        strcpy(i->data, tmp);

        float t = min->grade;
        min->grade = i->grade;
        i->grade = t;

        duyet(head);
    }
}
void InsertionSort(node *head)
{
    node *current = head->next;
    while (current != NULL)
    {
        node *key = current;
        node *prev = current->prev;

        while (prev != NULL && prev->grade > key->grade)
        {
            swapNode(prev, key);
            key = prev;
            prev = prev->prev;
        }
        duyet(head);
        current = current->next;
    }
}

void BubbleSort(node *head)
{
    node *last = NULL;
    int swapped;
    do
    {
        swapped = 0;
        node *current = head;
        while (current->next != last)
        {
            if (current->grade > current->next->grade)
            {
                swapNode(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        duyet(head);
        last = current;
    } while (swapped);
}
int main()
{
    node *head = NULL;
    while (1)
    {
        char s[1000];
        scanf("%s", s);
        if (strcmp(s, "#") == 0)
            break;
        float a;
        scanf(" %f", &a);
        if (0 <= a && a <= 10)
            pushback(&head, s, a);
    }
    char s[1000];
    scanf("%s", s);

    if (strcmp(s, "SelectionSort "))
    {
        selectionSort(head);
        return 0;
    }

    if (strcmp(s, "BubbleSort "))
    {
        BubbleSort(head);
        return 0;
    }

    if (strcmp(s, "InsertionSort "))
    {
        InsertionSort(head);
        return 0;
    }
}
