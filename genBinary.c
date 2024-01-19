#include <stdio.h>
int a[100000], n;

void printSolution()
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

void gen(int k)
{
    if (k > n)
    {
        printSolution();
        return;
    }
    a[k] = 0;
    gen(k + 1);
    a[k] = 1;
    gen(k+1);
}

int main()
{
    scanf("%d", &n);
    gen(1);
}