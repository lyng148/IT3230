#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data[21];
    int tansuat;
    struct node *next;
};

typedef struct node node;

node *Makenode(char *data)
{
    node *Newnode = (node *)malloc(sizeof(node));
    strcpy(Newnode->data, data);
    Newnode->tansuat = 1;
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

void them(node **head, char *data)
{
    node *Newnode = Makenode(data);
    if (*head == NULL)
    {
        node *tmp = *head;
        *head = Newnode;
        free(tmp);
    }
    else
    {
        node *tmp = *head;
        int stt = 0;
        while (tmp != NULL)
        {
            if (strcmp(tmp->data, data) == 0)
            {
                tmp->tansuat++;
                stt = 1;
                break;
            }
            else
                tmp = tmp->next;
        }
        if (stt == 0)
        {
            node *tmp = *head;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = Newnode;
        }
    }
}

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%s %d\n", head->data, head->tansuat);
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    char s[21];
    while (scanf("%s", s) == 1)
    {
        them(&head, s);
    } 
    duyet(head); 
}