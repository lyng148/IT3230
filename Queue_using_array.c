#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue
{
    int front, rear, size;
    unsigned int capacity;
    int *array;
} queue;

//************************
//*TẠO QUEUE THEO KÍCH CỠ*
//************************
queue *Makequeue(unsigned int capacity)
{
    queue *Newqueue = (queue *)malloc(sizeof(queue));
    Newqueue->capacity = capacity;
    Newqueue->front = Newqueue->rear = -1;
    Newqueue->size = 0;
    Newqueue->array = (int *)malloc(capacity * sizeof(int));
    return Newqueue;
}
//*********************
//*KIỂM TRA QUEUE FULL*
//*********************
bool isFull(queue *Queue)
{
    return (Queue->size == Queue->capacity);
}

//**************************
//*KIỂM TRA QUEUE CHƯA FULL*
//**************************
bool isEmpty(queue *Queue)
{
    return (Queue->size == 0);
}

//**********************
//*THÊM X VÀO SAU QUEUE*
//**********************
void Enqueue(queue *queue, int x)
{
    if (isFull(queue))
    {
        printf("Queue FULL !!!\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->array[++(queue->rear)] = x;
    (queue->size)++;
    return;
}

//*****************************
//*ĐƯA PHẦN TỬ ĐẦU HÀNG ĐỢI RA*
//*****************************
int Dequeue(queue *queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    int k = queue->array[queue->front];
    (queue->front)++;
    if (queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    (queue->size)--;
    return k;
}

//**************************
//*XEM PHẦN TỬ ĐẦU HÀNG ĐỢI*
//**************************
int front(queue *queue)
{
    return queue->array[queue->front];
}

int main()
{
    int n;
    scanf("%d", &n);
    queue *q = Makequeue(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d", &a);
        if (a == 1){
            scanf("%d", &b);
            Enqueue(q, b);
        }
        else
        {
            printf("%d ", Dequeue(q));
        }
    }
}