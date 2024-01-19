#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int thutuc(int a[], int l, int r)
{

    int i = l - 1;
    int pivot = a[r];
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
            swap(&a[j], &a[++i]);
    }
    swap(&a[r], &a[++i]);
    return i;
}

void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int pos = thutuc(a, l, r);
        quicksort(a, l, pos - 1);
        quicksort(a, pos + 1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}