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
            (*q)->rear = NULL;
            return;
        }
    }

    (*q)->front = (*q)->front->next;
}

int main()
{
    int nums[] = {100, 80, 60, 70, 60, 75, 85};
    int numsSize = 7;

    int ans[1000];
    int j = 0;
    int stt = 0;
    int l_tmp = 0, l = 0;
    memset(ans, -1, 1000);

    queue *q = createQueue();
    for (int i = 0; i < numsSize; i++)
    {
        while (!isEmpty(q) && nums[i] < nums[Rear(q)])
        {
            if (stt == 0)
            {
                l_tmp = Rear(q);
                stt = 1;
            }
            ans[Rear(q)] = Rear(q) - l;
            delRear(&q);
        }
        addRear(&q, i);
        l = l_tmp;
        stt = 0;
    }
    while (!isEmpty(q))
    {
        ans[Rear(q)] = Rear(q) - l;
        delRear(&q);
    }
    ans[0] = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (ans[i] == -1) ans[i] = 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", ans[i]);
    }
}