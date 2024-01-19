#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000
#define MAX_LINE_LENGTH 256

typedef struct {
    char time[20];
    char type[5];
    char content[MAX_LINE_LENGTH];
} LogEntry;

// Function to determine the priority of log types
int typePriority(const char *type) {
    if (strcmp(type, "ERRO") == 0) return 2;
    if (strcmp(type, "WARN") == 0) return 3;
    if (strcmp(type, "INFO") == 0) return 1;
    return 0;
}

int compare(const void *a, const void *b) {
    LogEntry *entry1 = (LogEntry *)a;
    LogEntry *entry2 = (LogEntry *)b;

    // Sort by type (ERRO > WARN > INFO)
    int typeOrder = typePriority(entry2->type) - typePriority(entry1->type);
    if (typeOrder != 0) return typeOrder;

    // Sort by time (ascending)
    int timeOrder = strcmp(entry1->time, entry2->time);
    if (timeOrder != 0) return timeOrder;

    // Sort by content (ascending)
    return strcmp(entry1->content, entry2->content);
}

int main() {
    LogEntry entries[MAX_LINES];
    int count = 0;

    while (scanf("%19s %4s %[^\n]", entries[count].time, entries[count].type, entries[count].content) == 3) {
        count++;
    }

    qsort(entries, count, sizeof(LogEntry), compare);

    for (int i = 0; i < count; i++) {
        printf("%s %s %s\n", entries[i].time, entries[i].type, entries[i].content);
    }

    return 0;
}
