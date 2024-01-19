#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "todo_data.txt"

typedef struct {
    int id;
    char description[100];
    int completed;
} Task;

void addTask();
void listTasks();
void markTaskCompleted();
void deleteTask();
void loadTasksFromFile(Task tasks[], int *count);
void saveTasksToFile(Task tasks[], int count);

int main() {
    int choice;
    do {
        printf("\nTodo Application\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Mark Task Completed\n");
        printf("4. Delete Task\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 0:
                printf("Exiting application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void addTask() {
    Task task;
    printf("Enter task description: ");
    scanf("%99s", task.description);
    task.id = rand(); // Simple ID generation
    task.completed = 0;

    Task tasks[100];
    int count = 0;
    loadTasksFromFile(tasks, &count);

    tasks[count] = task;
    count++;

    saveTasksToFile(tasks, count);

    printf("Task added successfully.\n");
}

void listTasks() {
    Task tasks[100];
    int count = 0;
    loadTasksFromFile(tasks, &count);

    printf("\nTask List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Description: %s, Completed: %s\n",
               tasks[i].id, tasks[i].description,
               tasks[i].completed ? "Yes" : "No");
    }
}

void markTaskCompleted() {
    Task tasks[100];
    int count = 0;
    loadTasksFromFile(tasks, &count);

    int id;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            saveTasksToFile(tasks, count);
            printf("Task marked as completed.\n");
            return;
        }
    }

    printf("Task not found.\n");
}

void deleteTask() {
    Task tasks[100], newTasks[100];
    int count = 0, newCount = 0;
    loadTasksFromFile(tasks, &count);

    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (tasks[i].id != id) {
            newTasks[newCount++] = tasks[i];
        }
    }

    saveTasksToFile(newTasks, newCount);

    printf("Task deleted if it existed.\n");
}

void loadTasksFromFile(Task tasks[], int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;

    while (fscanf(file, "%d %99[^\n] %d\n", &tasks[*count].id, tasks[*count].description, &tasks[*count].completed) == 3) {
        (*count)++;
    }

    fclose(file);
}

void saveTasksToFile(Task tasks[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) return;

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d\n", tasks[i].id, tasks[i].description, tasks[i].completed);
    }

    fclose(file);
}
