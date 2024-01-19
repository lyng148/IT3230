#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1001
#define MAX_NUM 1001

typedef struct Profile
{
    char name[MAX_LEN];
    char email[MAX_LEN];
} Profile;

Profile students[MAX_NUM];
int n;

void insert(char *name, char *email)
{
    int i = n - 1;
    while (i >= 0)
    {
        int c = strcmp(students[i].name, name);
        if (c == 0)
        {
            printf("Name %s exists, do not insert\n", name);
            return;
        }
        else if (c > 0)
        {
            students[i + 1] = students[i];
            i--;
        }
        else
            break;
    }
    i++;
    strcpy(students[i].name, name);
    strcpy(students[i].email, email);
    n++;
}

void removeStudent(int idx)
{
    for (int i = idx; i < n - 1; i++)
        students[i] = students[i + 1];
    n--;
}

int binarySearch(int L, int R, char *name)
{
    if (L > R)
        return -1;
    if (L == R)
    {
        if (strcmp(students[L].name, name) == 0)
            return L;
        else
            return -1;
    }
    int m = (L + R) / 2;
    int c = strcmp(students[m].name, name);
    if (c == 0)
        return m;
    if (c < 0)
        return binarySearch(m + 1, R, name);
    return binarySearch(L, m - 1, name);
}

void processInsert()
{
    char name[256], email[256];
    scanf("%s%s", name, email);
    insert(name, email);
}

void processRemove()
{
    char name[256];
    scanf("%s", name);
    int idx = binarySearch(0, n - 1, name);
    if (idx == -1)
        printf("Not found %s\n", name);
    else
    {
        removeStudent(idx);
    }
}

void processFind()
{
    char name[256];
    scanf("%s", name);
    int idx = binarySearch(0, n - 1, name);
    if (idx == -1)
    {
        printf("Not found student %s\n", name);
    }
    else
    {
        printf("Found student %s, at position %d, email %s\n", students[idx].name, idx, students[idx].email);
    }
}

void printList()
{
    for (int i = 0; i < n; i++)
        printf("student[%d]: %s, %s\n", i, students[i].name, students[i].email);
}

int main() {
    char command[10];
    n = 0;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "Insert") == 0) {
            processInsert();
        } else if (strcmp(command, "Find") == 0) {
            processFind();
        } else if (strcmp(command, "Remove") == 0) {
            processRemove();
        } else if (strcmp(command, "Print") == 0) {
            printList();
        } else if (strcmp(command, "Quit") == 0) {
            break;
        }
    }

    return 0;
}
