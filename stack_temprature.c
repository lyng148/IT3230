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
    int n;
    scanf(" %d", &n);
    int a[n];
    node *stack = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &a[i]);
    }
    int res[n];
    for (int i = 0; i < n; i++)
    {
        while (stack != NULL && a[peek(stack)] < a[i]){
            int j = peek(stack);
            res[j] = i - j;
            pop(&stack);
        }
        push(&stack, i);
    }
    for (int i = 0; i < n; i++){
        printf("%d ", res[i]);
    }
}