#include <stdio.h>
#include <string.h>

int main()
{
    char stack[20001];
    memset(stack, 0, sizeof(stack));
    int top = -1;
    char a[10000];
    char b[10000];
    scanf("%s %s", a, b);
 

    int idx_a = strlen(a) - 1;
    int idx_b = strlen(b) - 1;
          
    int nho = 0;
    while (idx_a >= 0 && idx_b >= 0)
    {
        int sum = a[idx_a] - '0' + b[idx_b] - '0';
        if (nho == 1)
        {
            sum += 1;
            nho = 0;
        }
        idx_a--;
        idx_b--;
        if (sum < 10)
        {
            stack[++top] = sum;
            continue;
        }
        if (sum >= 10)
        {
            stack[++top] = sum - 10;
            nho = 1;
        }
    }
    while (idx_a >= 0)
    {
        int sum = a[idx_a] - '0';
        if (nho == 1)
        {
            sum += 1;
            nho = 0;
        }
        idx_a--;
        if (sum < 10)
        {
            stack[++top] = sum;
            continue;
        }
        if (sum >= 10)
        {
            stack[++top] = sum - 10;
            nho = 1;
        }
    }
    while (idx_b >= 0)
    {
        int sum = b[idx_b] - '0';
        if (nho == 1)
        {
            sum += 1;
            nho = 0;
        }
        idx_b--;
        if (sum < 10)
        {
            stack[++top] = sum;
            continue;
        }
        if (sum >= 10)
        {
            stack[++top] = sum - 10;
            nho = 1;
        }
    }
    if (nho == 1) stack[++top] = 1;

    for (int i = top; i >= 0; i--)
    {
        printf("%d", stack[i]);
    }
}
