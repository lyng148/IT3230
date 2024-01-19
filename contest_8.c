/* Problem: Sắp xếp trộn với danh sách liên kết
Description
Cho cấu trúc sau:
typedef struct Node {
char name[MAX_LEN];
float grade;
struct Node* previous;
struct Node* next;
} Node;
dùng để lưu thông tin sinh viên gồm tên (name) và điểm (grade). Hãy xây dựng danh sách sinh viên và sắp xếp danh sách đó theo thứ tự tăng dần bằng một trong ba giải thuật Merge Sort.
Mô tả dữ liệu vào-ra:
Dữ liệu vào gồm nhiều dòng, mỗi dòng gồm tên và điểm của một sinh viên ngăn cách nhau bởi dấu cách. Kết thúc việc nhập tên và điểm của sinh viên bằng một dòng chứa dấu #.
Dữ liệu ra danh sách tên của sinh viên (ngăn cách với nhau bởi dấu cách) sau khi đã sắp xếp
Ví dụ:
Input:
Thuy 5.5
Dang 6.5
Anh 4.5
Tung 10
Khoat 8.0
Truc 9.5
Linh 7.0
#
Output:
Anh Thuy Dang Linh Khoat Truc Tung
Lưu ý:
Điểm của sinh viên phải trong khoảng từ 0 đến 10, nếu nằm ngoài khoảng này thì không lưu vào dánh sách liên kết. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char name[MAX_LEN];
    float grade;
    struct Node *next;
    struct Node *previous;
} Node;

Node* makeNode(char* name, float grade) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Unable to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->grade = grade;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void pushBack(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->previous = lastNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

// Split a doubly linked list (DLL) into two DLLs of half sizes
Node* split(Node* head) {
    Node* fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = NULL;
    if (temp) temp->previous = NULL;
    return temp;
}

Node* merge(Node* first, Node* second) {
    if (!first)
        return second;

    if (!second)
        return first;

    if (first->grade < second->grade) {
        first->next = merge(first->next, second);
        first->next->previous = first;
        first->previous = NULL;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->previous = second;
        second->previous = NULL;
        return second;
    }
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next)
        return;

    Node* second = split(head);

    // Recur for left and right halves
    mergeSort(&head);
    mergeSort(&second);

    // Merge the two sorted halves
    *headRef = merge(head, second);
}

int main() {
    Node* head = NULL;
    char name[MAX_LEN];
    float grade;
    while (scanf("%s", name) && strcmp(name, "#") != 0) {
        scanf("%f", &grade);
        if (grade >= 0 && grade <= 10) {
            Node* newNode = makeNode(name, grade);
            pushBack(&head, newNode);
        }
    }

    mergeSort(&head);
    printList(head);

    // Free the allocated memory
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
