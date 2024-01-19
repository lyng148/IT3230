#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Qnode
{
    int data;
    struct Qnode *next;
} qnode;

typedef struct Queue
{
    qnode *front;
    qnode *rear;
} queue;

//********************************
//*HÀM TẠO MỘT NODE MỚI CHO QUEUE*
//********************************
qnode *Makenode(int x)
{
    qnode *Newnode = (qnode *)malloc(sizeof(qnode));
    Newnode->data = x;
    Newnode->next = NULL;
    return Newnode;
}

//************************
//*HÀM TẠO MỘT QUEUE RỖNG*
//************************
queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

int size(queue *q)
{
    int count = 0;
    qnode *tmp = q->front; // Ở ĐÂ, CHÚN TA CẦN MỘT BIẾN TẠM, VÌ KHÔNG HIÊU VÌ SAO NẾU KHONG DÙNG, HÀM THAY ĐỔI TRỰC TIẾP GIÁ TRỊ, GÂY RA SAI
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

bool isEmpty(queue *q)
{
    return q->front == NULL;
}

int Front(queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->front->data;
}

int Rear(queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->rear->data;
}

void addFront(queue **q, int x)
{
    qnode *Newnode = Makenode(x);
    if (isEmpty(*q))
    {
        (*q)->front = Newnode;
        (*q)->rear = Newnode;
    }
    else
    {
        Newnode->next = (*q)->front;
        (*q)->front = Newnode;
        return;
    }
}

void addRear(queue **q, int x)
{
    qnode *Newnode = Makenode(x);
    if (isEmpty(*q))
    {
        (*q)->front = Newnode;
        (*q)->rear = Newnode;
    }
    else
    {
        (*q)->rear->next = Newnode;
        (*q)->rear = Newnode;
    }
}

void delRear(queue **q)
{
    if (isEmpty(*q))
        return;
    else
    {
        if ((*q)->front->next == NULL)
        {
            (*q)->front = NULL;
            (*q)->rear = NULL;
            return;
        }
    }

    qnode *tmp = (*q)->front;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    (*q)->rear = tmp;
    return;
}

void delFront(queue **q)
{
    if (isEmpty(*q))
        return;
    else
    {
        if ((*q)->front->next == NULL)
        {
            (*q)->front = NULL;
        }
    }

    (*q)->front = (*q)->front->next;
}

int main()
{
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int numsSize = 8;
    int k = 3;

    queue *q = createQueue();
    int *ans = (int *)malloc((numsSize - k + 1) * sizeof(int));
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        while (!isEmpty(q) && nums[i] > nums[Rear(q)])
        {
            delRear(&q);
        }

        addRear(&q, i);

        if (Front(q) + k == i)
        {
            delFront(&q);
        }

        if (i >= k - 1)
        {
            ans[j] = nums[Front(q)];
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        printf("%d ", ans[i]);
    }
}