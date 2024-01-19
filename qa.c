#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 129

typedef struct {
    int id;
    char name[MAX_LEN];
} Student;

Student** initHashTable(int size) {
    Student** hashTable = (Student**) malloc(size * sizeof(Student*));
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }
    return hashTable;
}

int hash(int key, int size) {
    return key % size;
}

int quadraticProbe(int key, int size, int c1, int c2, int i) {
    return (hash(key, size) + c1 * i + c2 * i * i) % size;
}

int h1(int key, int size) {
    return key % 13;
}

int h2(int key, int size) {
    return 7 - (key % 7);
}

int doubleHash(int key, int size, int i) {
    return (h1(key, size) + i * h2(key, size)) % size;
}


void insert(Student** hashTable, int size, Student* student, char* probingType, int c1, int c2) {
    int index, i = 0;
    do {
        if (strcmp(probingType, "linear") == 0) {
            index = (hash(student->id, size) + i) % size;
        } else if (strcmp(probingType, "quadratic") == 0) {
            index = quadraticProbe(student->id, size, c1, c2, i);
        } else if (strcmp(probingType, "double") == 0) {
            index = doubleHash(student->id, size, i);
        } else {
            printf("Invalid probing type.\n");
            return;
        }
        if (hashTable[index] == NULL) {
            hashTable[index] = student;
            return;
        }
        i++;
    } while (i < size);
}

Student* search(Student** hashTable, int size, int id, int *pos) {
    for (int i = 0; i < size; i++) {
        if (hashTable[i] != NULL && hashTable[i]->id == id) {
            *pos = i;
            return hashTable[i];
        }
    }
    return NULL;
}

void printHashTable(Student** hashTable, int size) {
    for (int i = 0; i < size; i++) {
        if (hashTable[i] != NULL) {
            printf("%s ", hashTable[i]->name);
        }
    }
    printf("\n");
}

int main() {
    int m, c1, c2;
    char probingType[10];

    scanf("%d %s", &m, probingType);
     if (strcmp(probingType, "linear") != 0 && strcmp(probingType, "quadratic") != 0 && strcmp(probingType, "double") != 0)
    {
        printf("Invalid probing type.\n");
        return 0;
    }
    if (strcmp(probingType, "quadratic") == 0) {
        scanf("%d %d", &c1, &c2);
    }

    Student** hashTable = initHashTable(m);

    for (int i = 0; i < m; i++) {
        Student* newStudent = (Student*)malloc(sizeof(Student));
        scanf("%d %s", &newStudent->id, newStudent->name);
        insert(hashTable, m, newStudent, probingType, c1, c2);
    }
    getchar(); 

    char line[256];
    int id;

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "Search %d", &id) == 1) {
            int pos = -1;
            Student* foundStudent = search(hashTable, m, id, &pos);
            if (foundStudent != NULL) {
                printf("Found student name %s id %d at position %d.\n", foundStudent->name, id, pos);
            } else {
                printf("Id %d not found.\n", id);
            }
        } else if (strncmp(line, "Print", 5) == 0) {
            printHashTable(hashTable, m);
        } else if (strncmp(line, "Quit", 4) == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    for (int i = 0; i < m; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }
    free(hashTable);

    return 0;
}
