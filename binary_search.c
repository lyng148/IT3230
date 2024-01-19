#include <stdio.h>

int bs(int *nums, int l, int r, int k) // return index
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == k)
            return mid;
        else if (nums[mid] < k)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return -1;
}

int bs_recur(int *nums, int l, int r, int k)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == k)
            return mid;
        else if (nums[mid] < k)
        {
            return bs_recur(nums, mid + 1, r, k);
        }
        else
            return bs_recur(nums, l, mid - 1, k);
    }
    return -1;
}

int main()
{
    int nums[] = {1, 3, 5, 66, 3333, 4444123, 32312323};
    int numsSize = 7;
    printf("%d", bs_recur(nums, 0, numsSize, 3333));
}