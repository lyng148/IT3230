#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int count(int *arr)
{
    int counter = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] != -1)
            counter++;
    }
    return counter;
}

void addFront(int *arr, int x, int *front, int *rear)
{
    if (*front == 0 && *rear == MAX - 1)
    {
        printf("Queue full!\n");
        return;
    }

    if (*front == -1)
    {
        *front = *rear = 0;
        arr[*front] = x;
        return;
    }

    if (*rear != MAX - 1)
    {
        int c = count(arr);
        int k = *rear + 1;
        for (int i = 0; i < c; i++)
        {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k] = x;
        *front = k; // vì hàng đợi liên tục gán dần giá trị của thằng đằng trc cho thằng dăng sau, nên chạy đén cuối gắn k = front
        (*rear)++;  // vì hàng đợi đã xích lên, nên ta tăng rear lên 1 (mình nghĩ ở trên kh cần thiết gắn front = k, chút nữa mình sẽ thử bỏ)
    }
    else
    {
        (*front)--;
        arr[*front] = x;
    }
}

void addRear(int *arr, int x, int *front, int *rear)
{
    if (*front == 0 && *rear == MAX - 1)
    {
        printf("Queue full!\n");
        return;
    }

    if (*front == -1)
    {
        *front = 0;
    }
    (*rear)++;
    arr[*rear] = x;
}

int delFront(int *arr, int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Queue empty\n");
        return -1;
    }

    int k = arr[*front];
    arr[*front] = 0;

    if (*front > *rear)
    {
        *front = *rear = -1;
    }
    else
        (*front)++;
    return k;
}

int delRear(int *arr, int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Queue empty!\n");
        return -1;
    }

    int k = arr[*rear];
    arr[*rear] = 0;

    if (*front > *rear)
    {
        *front = *rear = -1;
    }
    else
        (*rear)--;
    return k;
}

int Front(int *arr, int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Queue empty!\n");
        return -1;
    }
    return arr[*front];
}

int Rear(int *arr, int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Queue empty!\n");
        return -1;
    }
    return arr[*rear];
}

void display(int *arr, int *front, int *rear)
{
    for (int i = *front; i <= *rear; i++)
    {
        printf("%d", arr[i]);
    }
}

bool isEmpty(int *arr, int *front, int *rear)
{
    return (*front == -1 && *rear == -1);
}

bool isFull(int *arr, int *front, int *rear)
{
    return (*front == 0 && *rear == MAX - 1);
}

int main()
{
    int nums[] = {0, 2, 1, -2, 3, 4, 1};
    int k = 3;
    int ans[100];
    int deque[1000];
    int front, rear;
    front = rear = -1;
    for (int i = 0; i < 100; i++){
        deque[i]
    }
}