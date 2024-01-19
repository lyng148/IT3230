#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

bool isEmpty(node *head)
{
    return head == NULL;
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

int getPriority(int x)
{
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else
        return -1;
}

int main(){
    node *head = NULL;
    char s[1000];
    fgets(s, 1000, stdin);
    for (int i = 0; i < strlen(s) - 1; i++){
        if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/'){
            push(&head, s[i] - '0');
        }
        else
        {
            if (size(head) < 2){
                return 0;
            }
            int a = peek(head);
            pop(&head);
            int b = peek(head);
            pop(&head);
            int result;
            if (s[i] == '+') result = a + b;
            if (s[i] == '-') result = a - b;
            if (s[i] == '*') result = a * b;
            if (s[i] == '/') result = a / b;
            push(&head, result);
        }
    }
    printf("%d\n",head->data);
}