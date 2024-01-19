#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head = NULL; // Con trỏ đầu danh sách

// Hàm thêm một phần tử vào cuối danh sách
void addLast(int k) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = k;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Hàm thêm một phần tử vào đầu danh sách
void addFirst(int k) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = k;
    newNode->next = head;
    head = newNode;
}

// Hàm thêm một phần tử sau một giá trị đã cho
void addAfter(int u, int v) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == v) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->value = u;
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
    }
}

// Hàm thêm một phần tử trước một giá trị đã cho
void addBefore(int u, int v) {
    if (head == NULL) {
        return;
    }
    
    if (head->value == v) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = u;
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->value == v) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->value = u;
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
    }
}

// Hàm loại bỏ tất cả các phần tử có giá trị bằng k
void removee(int k) {
    while (head != NULL && head->value == k) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    if (head == NULL) {
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->next->value == k) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Hàm đảo ngược danh sách
void reverse() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// Hàm in danh sách
void printList() {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    char buff[100];
    int k, u, v;

    // Đọc dãy số từ bàn phím
    fgets(buff, sizeof(buff), stdin);

    char* token = strtok(buff, " ");
    while (token != NULL) {
        k = atoi(token);
        addLast(k);
        token = strtok(NULL, " ");
    }

    while (1) {
        fgets(buff, sizeof(buff), stdin);
        if (buff[0] == '#') {
            break;
        }

        char* command = strtok(buff, " ");
        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &k);
            addLast(k);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &k);
            addFirst(k);
        } else if (strcmp(command, "addafter") == 0) {
            scanf("%d %d", &u, &v);
            addAfter(u, v);
        } else if (strcmp(command, "addbefore") == 0) {
            scanf("%d %d", &u, &v);
            addBefore(u, v);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &k);
            removee(k);
        }
        // Đọc dòng mới để bỏ ký tự newline
        fgets(buff, sizeof(buff), stdin);
    }

    printList();

    // Giải phóng bộ nhớ
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
