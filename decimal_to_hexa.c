#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char convert(int a)
{
    if (a == 0)
        return '0';
    if (a == 1)
        return '1';
    if (a == 2)
        return '2';
    if (a == 3)
        return '3';
    if (a == 4)
        return '4';
    if (a == 5)
        return '5';
    if (a == 6)
        return '6';
    if (a == 7)
        return '7';
    if (a == 8)
        return '8';
    if (a == 9)
        return '9';
    if (a == 10)
        return 'A';
    if (a == 11)
        return 'B';
    if (a == 12)
        return 'C';
    if (a == 13)
        return 'D';
    if (a == 14)
        return 'E';
    if (a == 15)
        return 'F';
}

typedef struct node
{
    int val;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

node *Makenode(int val)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->val = val;
    Newnode->next = NULL;
    return Newnode;
}

stack *stackInit()
{
    stack *Newstack = (stack *)malloc(sizeof(stack));
    Newstack->top = NULL;
    return Newstack;
}

bool stackEmpty(stack *s)
{
    return s->top == NULL;
}

void stackPush(stack *s, int val)
{
    node *Newnode = Makenode(val);
    Newnode->next = s->top;
    s->top = Newnode;
}

int stackPop(stack *s)
{
    if (stackEmpty(s))
    {
        printf("Error: Stack empty!\nError code: ");
        return -1;
    }
    node *tmp = s->top;
    int val = s->top->val;
    s->top = s->top->next;
    free(tmp);
    return val;
}

int main()
{
    stack *s = stackInit();
    double n;
    scanf("%lf", &n);
    double a = n - (int)n; // a luu phan sau dau phay
    n -= a;                // n luu phan truoc dau phay
    int b = (int)n;
    while (b > 0)
    {
        stackPush(s, convert(b % 16));
        b /= 16;
    }

    if (stackEmpty(s))
        printf("0");
    while (!stackEmpty(s))
    {
        printf("%c", stackPop(s));
    }
    if (a != 0)
    {
        printf(".");
        do
        {
            a *= 16;
            int phannguyen = (int)a;
            printf("%c", convert(phannguyen));
            a -= phannguyen;
        } while (a != 0);
    }
}