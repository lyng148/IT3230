#include <stdio.h>

int max(int a, int b){return a > b ? a : b;}

int main()
{
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int numsSize = 9;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum1 += nums[i];
        if (sum1 <= 0) sum1 = 0;
        else sum2 = max(sum2, sum1);
    }
    printf("%d", sum2);
}