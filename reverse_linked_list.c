#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *Makenode(int data)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->data = data;
    Newnode->next = NULL;
    return Newnode;
}

void pushback(node **head, int x)
{
    node *Newnode = Makenode(x);
    if (*head == NULL)
    {
        *head = Newnode;
        return;
    }
    else
    {
        node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = Newnode;
    }
}

int size(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
/* //************************************************
//*ĐẢO NGỰỢC DANH SÁCH LIÊN KẾT KHÔNG DÙNG ĐỆ QUY*
//************************************************
node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        node *Nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Nextnode;
    }
    return prev;
} */

//*************************************************
//*ĐẢO NGƯỢC DANH SÁCH LIÊN KẾT ĐƠN SỬ DỤNG ĐỆ QUY*
//*************************************************
node *reverse(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL)
    {
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* node *reverse_pair(node *head) //not optimized
{
    node *curr = head->next;
    node *prev = head;
    node *start = curr;
    node *Nodenextnext;
    node *Nodenext;
    int size2 = size(head);
    if (size2 % 2 == 0)
    {
        while (curr->next != NULL)
        {

            Nodenextnext = curr->next->next;
            Nodenext = curr->next;

            curr->next = prev;
            prev->next = Nodenextnext;
            prev = Nodenext;
            curr = Nodenextnext;
        }
        curr->next = prev;
        prev->next = NULL;
    }
    else
    {
    while (curr->next->next != NULL)
    {

        Nodenextnext = curr->next->next;
        Nodenext = curr->next;

        curr->next = prev;
        prev->next = Nodenextnext;
        prev = Nodenext;
        curr = Nodenextnext;
    }
    node* next2 = curr->next;
    curr->next = prev;
    prev->next = next2;
    next2->next = NULL;
    }
    return start;
}
 */

//*************************************************************
//*TỐI ƯU ĐỂ ĐẢO NGƯỢC LINKED LIST THEO NHÓM VỚI ĐỘ DÀI BẤT KÌ*
//*************************************************************
node *reverse_pair(node *head, int k)
{
    // base case
    if (!head)
        return NULL;
    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse_pair(next, k);

    /* prev is new head of the input list */
    return prev;
}

//***************************************
//*ĐẢO NGƯỢC VỚI LEFT VÀ RIGHT CHO TRƯỚC*
//***************************************
node *reverseBetween(node *head, int left, int right)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (left == right)
        return head;
    int i = 0;
    node *start = head;
    node *prev_left = NULL;
    while (i < left - 1)
    {
        prev_left = head;
        head = head->next;
        i++;
    }
    node *curr = head->next;
    node *prev = head;
    node *head_reverse = head;
    while (i < right - 1)
    {
        node *Nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Nextnode;
        i++;
    }
    if (prev_left != NULL)
    {
        prev_left->next = prev;
    }
    head_reverse->next = curr;
    if (prev_left == NULL)
        return prev;
    else
        return start;
}

int main()
{
    node *head = NULL;
    pushback(&head, 1);
    pushback(&head, 2);
    pushback(&head, 3);
    pushback(&head, 4);
    pushback(&head, 5);
    duyet(head);
    printf("\n");
    head = reverse(head);
    duyet(head);
}