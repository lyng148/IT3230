/* 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Medium
3.1K
132
Companies
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.



Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4.
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109 */

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
    if ((*q)->front->next == NULL)
    {
        (*q)->front = NULL;
        return;
    }

    (*q)->front = (*q)->front->next;
}

int main()
{
    int nums[] = {12, 3, 4, 6, 9, 1};
    int numsSize = 6;
    int limit = 7;

    queue *q_inc = createQueue();
    queue *q_dec = createQueue();
    int max = 0;
    int left = 0;

    for (int i = 0; i < numsSize; i++)
    {
        while (!isEmpty(q_inc) && nums[i] < nums[Rear(q_inc)])
        {
            delRear(&q_inc);
        }

        addRear(&q_inc, i);

        while (!isEmpty(q_dec) && nums[i] > nums[Rear(q_dec)])
        {
            delRear(&q_dec);
        }

        addRear(&q_dec, i);

        if (nums[Front(q_dec)] - nums[Front(q_inc)] > limit)
        {
            left = Front(q_dec);
            delFront(&q_dec);
        }
        else
        {
            if (i - left > max)
                max = i - left;
        }
    }
    printf("%d ", max);
}