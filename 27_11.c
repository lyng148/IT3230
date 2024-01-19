#include <stdio.h>
#include <stdlib.h>

int b[10000], n, count = 0;

void in()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", b[i]);
    }
    count++;
    printf("\n");
}

void thu(int i, int **a, int *lengths)
{
    if (i == 1)
    {
        for (int j = 1; j <= 9; j++)
        {
            b[i] = j;
            if (i == n)
                in();
            else
                thu(i + 1, a, lengths);
        }
    }
    else
    for (int j = 0; j < lengths[b[i - 1]]; j++)
    {
        b[i] = a[b[i - 1]][j];
        if (i == n)
            in();
        else
            thu(i + 1, a, lengths);
    }
}

int main()
{
    int *a[10];
    int lengths[10] = {2, 2, 2, 2, 3, 0, 3, 2, 2, 2};

    // Dynamically allocate memory for each sub-array
    a[0] = (int *)malloc(2 * sizeof(int));
    a[0][0] = 4;
    a[0][1] = 6;

    a[1] = (int *)malloc(2 * sizeof(int));
    a[1][0] = 6;
    a[1][1] = 8;

    a[2] = (int *)malloc(2 * sizeof(int));
    a[2][0] = 7;
    a[2][1] = 9;

    a[3] = (int *)malloc(2 * sizeof(int));
    a[3][0] = 4;
    a[3][1] = 8;

    a[4] = (int *)malloc(3 * sizeof(int));
    a[4][0] = 0;
    a[4][1] = 3;
    a[4][2] = 9;

    // a[5] is an empty set
    a[5] = NULL;

    a[6] = (int *)malloc(3 * sizeof(int));
    a[6][0] = 0;
    a[6][1] = 1;
    a[6][2] = 7;

    a[7] = (int *)malloc(2 * sizeof(int));
    a[7][0] = 2;
    a[7][1] = 6;

    a[8] = (int *)malloc(2 * sizeof(int));
    a[8][0] = 1;
    a[8][1] = 3;

    a[9] = (int *)malloc(2 * sizeof(int));
    a[9][0] = 2;
    a[9][1] = 4;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int j = 0; j < 10; j++)
    {
        b[0] = j;
        thu(1, a, lengths);
    }

    // Free the allocated memory
    for (int i = 0; i < 10; i++)
    {
        free(a[i]);
    }
    printf("%d", count);
    return 0;
}