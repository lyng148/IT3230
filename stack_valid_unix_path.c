//***************************
//*9/10 TEST - NEED IMPROVED*
//***************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    while (head != NULL)
    {
        printf("%c", head->data);
        head = head->next;
    }
}

node* reverse(node *head){
    node* curr = head;
    node *prev = NULL;
    while (curr != NULL){
        node *Nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Nextnode;
    }
    return prev;
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

void push(node **head, int x)
{
    node *Newnode = Makenode(x);
    Newnode->next = (*head);
    (*head) = Newnode;
}

void pop(node **head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    (*head) = (*head)->next;
    free(tmp);
}

int peek(node *head)
{
    if (head != NULL)
        return head->data;
    else
        return 0;
}

int main()
{
    node *head = NULL;
    char s[1024];
    int count = 0;
    fgets(s, sizeof(s), stdin);
    int l = strlen(s) - 1;
    for (int i = 0; i < l; i++)
    {
        push(&head, s[i]);
        if (s[i] == '.')
        {
            count++;
            if (s[i + 1] != '.')
            {
                if (count == 1 || count == 2)
                {
                    for (int j = 0; j < count; j++)
                    {
                        pop(&head);
                    }
                }
            }
        }
        if (s[i - 1] == '/' && s[i] == '/')
            pop(&head);
        if (s[i + 1] == '\n' && s[i] == '/')
            pop(&head);
    }
    head = reverse(head);
    duyet(head);
}