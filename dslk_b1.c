#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char MSSV[21];
    char hoten[51];
    double gpa;
    struct node *next;
} node;

node *Makenode(char *MSSV, char *hoten, double gpa)
{
    node *Newnode = (node *)malloc(sizeof(node));
    strcpy(Newnode->MSSV, MSSV);
    strcpy(Newnode->hoten, hoten);
    Newnode->gpa = gpa;
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

void pushfront(node **head, char *MSSV, char *hoten, double gpa)
{
    node *Newnode = Makenode(MSSV, hoten, gpa);
    Newnode->next = *head;
    *head = Newnode;
}

void pushback(node **head, char *MSSV, char *hoten, double gpa)
{
    node *Newnode = Makenode(MSSV, hoten, gpa);
    if (*head == NULL)
        *head = Newnode;
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

void pushmid(node **head, int k, char *MSSV, char *hoten, double gpa)
{
    node *Newnode = Makenode(MSSV, hoten, gpa);
    if (k < 0 || k > size(*head) + 1)
        return;
    if (k == 1)
        pushfront(head, MSSV, hoten, gpa);
    else if (k == size(*head) + 1)
        pushback(head, MSSV, hoten, gpa);
    else
    {
        int i = 1;
        node *tmp = *head;
        while (i < k - 1)
        {
            i++;
            tmp = tmp->next;
        }
        Newnode->next = tmp->next;
        tmp->next = Newnode;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        scanf("%d", &k);

        getchar();
        char MSSV[21];
        char hoten[51];
        char gpa[6];
        
        fgets(MSSV, 20, stdin);
        MSSV[strlen(MSSV) - 1] = '\0';
        fgets(hoten, 50, stdin);
        hoten[strlen(hoten) - 1] = '\0';
        fgets(gpa, sizeof(gpa), stdin);
        sscanf(gpa, "%lf", &gpa);
        printf("%s %s %lf\n", MSSV, hoten, gpa);
    }
}
