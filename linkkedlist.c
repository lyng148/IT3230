#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *Makenode(int x)
{
    node *Newnode = (node *)malloc(sizeof(node)); // cap phat 1 node
    Newnode->data = x;
    Newnode->next = NULL;
    return Newnode; // tra ve con tro den node moi
}

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void pushfront(node **head, int x)
{
    node *Newnode = Makenode(x);
    Newnode->next = (*head);
    (*head) = Newnode;
}

void pushback(node **head, int x)
{
    node *Newnode = Makenode(x);
    if (*head == NULL)
    {
        *head = Newnode;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = Newnode;
    return;
}

void insert(node **head, int k, int x)
{
    if (k == 1)
        pushfront(head, x);
    else if (k == size(*head) + 1)
        pushback(head, x);
    else
    {
        node *Newnode = Makenode(x);
        int i = 1;
        node *temp = *head;
        while (i != k - 1)
        {
            i++;
            temp = temp->next;
        }
        Newnode->next = temp->next;
        temp->next = Newnode;
    }
}

void removehead(node **head)
{
    node *tmp = *head;
    (*head) = (*head)->next;
    free(tmp);
}

void removetail(node *head)
{
    if (head == NULL)
        return;
    int i = 1;
    while (i <= size(head))
    {
        i++;
        head = (head)->next;
    }
    node *tmp = head->next;
    head->next = NULL;
    free(tmp);
}

void removemid(node **head, int k)
{
    if (k == 1)
        removehead(head);
    else if (k == size(*head))
        removetail(*head);
    else
    {
        node *tmp2 = *head;
        int i = 1;
        while (i < k - 1)
        {
            i++;
            tmp2 = tmp2->next;
        }
        node *tmp = tmp2->next;
        tmp2->next = tmp2->next->next;
        free(tmp);
    }
}

void sort(node **head)
{
    for (node *i = *head; i != NULL; i = i->next)
    {
        for (node *j = i; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void addAfterMax(node **head, int data)
{
    node *Newnode = Makenode(data);
    if (*head == NULL)
    {
        *head = Makenode(0);
        (*head)->next = Newnode;
        return;
    }
    else
    {
        int max = 0;
        node *tmp = *head;
        while (tmp != NULL)
        {
            if (tmp->data > max)
                max = tmp->data;
            tmp = tmp->next;
        }
        tmp = *head;
        while (tmp != NULL)
        {
            if (tmp->data == max)
            {
                Newnode->next = tmp->next;
                tmp->next = Newnode;
                return;
            }
            tmp = tmp->next;
        }
    }
}

node* remove_odd(node *head)
{
    while (head != NULL && (head)->data % 2 == 1)
    {
        head = (head)->next;
    }

    if (head == NULL)
        return head;

    node *prev = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 == 1)
        {
            prev->next = curr->next;
            node *p = curr;
            curr = curr->next;
            free(p);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

Node* tinhTongHaiDS(Node* head1, Node* head2) {
    // Tạo nút đầu tiên cho danh sách mới.
    Node* head3 = NULL;
    Node** ptr = &head3;

    while (head1 != NULL || head2 != NULL) {
        // Tính tổng hai nút, coi giá trị của nút không tồn tại là 0.
        int sum = 0;
        if (head1 != NULL) {
            sum += head1->inf;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            sum += head2->inf;
            head2 = head2->next;
        }

        // Tạo nút mới và thêm vào danh sách kết quả.
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->inf = sum;
        newNode->next = NULL;
        
        // Liên kết nút mới vào danh sách kết quả.
        *ptr = newNode;
        ptr = &newNode->next;
    }

    return head3;
}

node *head3 = NULL
node **ptr = &head3

*ptr = Newnode
ptr = &Newnode->next


int main()
{
    node *head = Makenode(3);
    pushback(&head, 5);
    insert(&head, 2, 4);
    removemid(&head, 1);
    pushback(&head, 56);
    insert(&head, 3, 44324);
    sort(&head);
    addAfterMax(&head, 69);
    pushfront(&head, 1);
    pushfront(&head, 3);
    pushfront(&head, 5);
    duyet(head);
    printf("\n");
    head = remove_odd(head);
    duyet(head);
}