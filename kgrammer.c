//C 
#include <stdio.h> 
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize){
    int sum = 0, ans = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        ans = ans > sum ? ans : sum;
        if (sum < 0) sum = 0;
    }
    return ans;
}

int main() 
{ 
    int numsSize;
    scanf("%d", &numsSize);
    int* nums = (int*)malloc(1000001 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }
    int max = maxSubArray(nums, numsSize);
    printf("%d", max);
}