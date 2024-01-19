#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char name[MAX_LEN];
    float grade;
    struct Node* next;
    struct Node* previous;
} Node;

Node* makeNode(char* name, float grade) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->grade = grade;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, Node* newNode) {
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

void swapNode(Node* a, Node* b) {
    float tempGrade = a->grade;
    a->grade = b->grade;
    b->grade = tempGrade;
    char tempName[MAX_LEN];
    strcpy(tempName, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempName); 
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

void SelectionSort(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* minNode = current;
        Node* nextNode = current->next;

        while (nextNode != NULL) {
            if (minNode->grade > nextNode->grade) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }
        swapNode(current, minNode);
        printList(head);
        current = current->next;
    }
}

void InsertionSort(Node* head) {
    Node* current = head->next;
    while (current != NULL) {
        Node* key = current;
        Node* prev = current->previous;

        while (prev != NULL && prev->grade > key->grade) {
            swapNode(prev, key);
            key = prev;
            prev = prev->previous;
        }
        printList(head);
        current = current->next;
    }
}

void BubbleSort(Node* head) {
    Node* last = NULL;
    int swapped;
    do {
        swapped = 0;
        Node* current = head;
        while (current->next != last) {
            if (current->grade > current->next->grade) {
                swapNode(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        printList(head);
        last = current;
    } while (swapped);
}

int main() {
    Node* head = NULL;
    char name[MAX_LEN];
    float grade;
    while (scanf("%s", name) && strcmp(name, "#") != 0) {
        scanf("%f", &grade);
        if (grade >= 0 && grade <= 10){
            Node* newNode = makeNode(name, grade);
            insertNode(&head, newNode);
        }
    }

    char sort[20];
    scanf("%s", &sort);

    if (strcmp(sort, "SelectionSort") == 0) {
        SelectionSort(head);
    } else if (strcmp(sort, "InsertionSort") == 0) {
        InsertionSort(head);
    } else if (strcmp(sort, "BubbleSort") == 0) {
        BubbleSort(head);
    }
	else{
		printf("Wrong Command");
		return 0;
	}
    return 0;
}
