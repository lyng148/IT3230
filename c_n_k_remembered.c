#include <stdio.h>
#include <string.h>

int c[1000][1000];

int kCn(int k, int n)
{
    if (k == 0 || k == n)
    {
        c[k][n] = 1;
    }
    else
    {
        if (c[k][n] < 0)
        {
            c[k][n] = kCn(k - 1, n - 1) + kCn(k, n - 1);
        }
    }
    return c[k][n];
}

int main()
{
    memset(c, -1, sizeof(c)); 
    printf("%d", kCn(10,20));
}