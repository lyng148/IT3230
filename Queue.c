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

int front(queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->front->data;
}

void enqueue(queue **q, int x)
{
    qnode *Nenwode = Makenode(x);
    if (isEmpty(*q))
    {
        (*q)->front = Nenwode;
        (*q)->rear = Nenwode;
    }
    else
    {
        (*q)->rear->next = Nenwode;
        (*q)->rear = Nenwode;
    }
}

int dequeue(queue **q)
{
    if (isEmpty(*q))
    {
        return -1;
    }
    else
    {
        int k = (*q)->front->data;
        (*q)->front = (*q)->front->next;
        return k;
    }
}

void duyet(queue *q)
{
    qnode *tmp = q->front;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main()
{
    queue *q = createQueue();
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        enqueue(&q, dequeue(&q));
    }
    duyet(q);
}
