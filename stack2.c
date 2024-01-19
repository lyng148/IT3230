#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

typedef struct Stack stack;

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}


//Function to push an integer into the stack.
void push(struct Stack* stack, int item)
{
    stack->array[stack->top + 1] = item;
}


//Function to remove an item from top of the stack.
int pop(struct Stack* stack)
{
    int k = stack->array[stack->top];
    stack->top -= 1;
    return k;
}

int main()
{
    stack *a = createStack(1000);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
      char opt[10];
      scanf("%s", opt);
      if (strcmp(opt, "push") == 0){
        int k;
        scanf("%d", &k);
        push(a, k);
      }
      else if (strcmp(opt, "pop") == 0){
        printf("%d ", pop(a));
      }
    }
}