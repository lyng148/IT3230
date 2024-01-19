#include <stdio.h>

void swap(int *a, int *b){int tmp = *a; *a = *b; *b = tmp;}

int thutuc(int *nums, int l, int r)
{
    int pivot = nums[r];
    int i = l;
    for (int j = l; j < r; j++)
    {
        if (nums[j] <= pivot)
        {
            swap(&nums[i++], &nums[j]);
        }
    }
    swap(&nums[i], &nums[r]);
    return i;
}

void quicksort(int *nums, int l, int r)
{
    if (l < r)
    {
        int pos = thutuc(nums, l, r);
        quicksort(nums, l, pos - 1);
        quicksort(nums, pos + 1, r);
    }
}

int main()
{
    int nums[] = {1, 3, 5,12, 22, 1,2, 4};
    int numsSize = 8;
    quicksort(nums, 0, numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

}