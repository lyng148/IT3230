#include <stdio.h>
#define ll long long

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (a[0] >a[1]) printf("%d ", a[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i + 1] < a[i])
            printf("%d ", i);
    }
    if (a[n-1] >a[n-2]) printf("%d ", a[n-1]);
}