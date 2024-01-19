#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *nums, int size)
{
  int min = 0;
  for (int i = 0; i < size - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (nums[j] < nums[min]) min = j;
    }
    swap(&nums[i], &nums[min]);
  }
  
}

int main()
{
  int n; scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  
  sort(a, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}