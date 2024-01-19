#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct stack
{
    int top;
    int stack[MAX];
} stack;

void init(stack *a)
{
    a->top = -1;
}

int empty(stack *a)
{
    return a->top == -1;
}

int full(stack *a)
{
    return a->top == MAX - 1;
}

void pop(stack *a)
{
    if (empty(a))
        printf("Stack underflow");
    else
        (a->top)--;
}

void push(stack *a, int x)
{
    if (full(a))
        printf("Stack overflow");
    else
        a->stack[++(a->top)] = x;
}

int main()
{
    stack a;
    init(&a);
    pop(&a);
}
