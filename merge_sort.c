#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int l, int m, int r)
{
    int k = l;
    int n1 = m - l + 1;
    int n2 = r - m;
    int x[n1], y[n2];
    for (int i = 0; i < n1; i++)
    {
        x[i] = a[l++];
    }
    for (int i = 0; i < n2; i++)
    {
        y[i] = a[l++];
    }

    int i = 0, j = 0, index = k;
    while (i < n1 && j < n2)
    {
        if (x[i] < y[j])
        {
            a[index++] = x[i++];
        }
        else
            a[index++] = y[j++];
    }

    while (i < n1)
    {
        a[index++] = x[i++];
    }

    while (j < n2)
    {
        a[index++] = y[j++];
    }
}

void sort(int *nums, int l, int r)
{
    int m = (r + l) / 2;
    if (l < r)
    {
        sort(nums, l, m);
        sort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
}

int main()
{
    int nums[] = {1, 3, 5,12, 22, 1,2, 4};
    int numsSize = 8;
    sort(nums, 0, numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
}

/* //LEETCODE VERSION void merge(int *a, int l, int m, int r) {
    int k = l;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *x = (int *)malloc(n1 * sizeof(int));
    int *y = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        x[i] = a[l++];
    }
    for (int i = 0; i < n2; i++) {
        y[i] = a[l++];
    }

    int i = 0, j = 0, index = k;
    while (i < n1 && j < n2) {
        if (x[i] < y[j]) {
            a[index++] = x[i++];
        } else {
            a[index++] = y[j++];
        }
    }

    while (i < n1) {
        a[index++] = x[i++];
    }

    while (j < n2) {
        a[index++] = y[j++];
    }
    free(x);
    free(y);
} */

void sort(int *nums, int l, int r, int numsSize) {
    if (l < r && l >= 0 && r >= 0 && r < numsSize && l < numsSize) {
        int m = (r + l) / 2;
        sort(nums, l, m, numsSize); // Pass the size of the left subarray to the sort() function.
        sort(nums, m + 1, r, numsSize); // Pass the size of the right subarray to the sort() function.
        merge(nums, l, m, r);
    }
}

int *sortArray(int *nums, int numsSize, int *returnSize) {
    int *ans = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
    }

    sort(ans, 0, numsSize - 1, numsSize);
    *returnSize = numsSize;
    return ans;
}
