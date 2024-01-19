#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char id[101];
    char name[101];
    double gpa;
    struct node *next;
} node;

node *Makenode(char *id, char *name, double gpa)
{
    node *Newnode = (node *)malloc(sizeof(node));
    strcpy(Newnode->id, id);
    strcpy(Newnode->name, name);
    Newnode->gpa = gpa;
    Newnode->next = NULL; 
    return Newnode;
}

int size(node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

void duyet_codk(node* head, double gpa){
    while(head != NULL){
        if (head->gpa == gpa){
            printf("%s %s %.2lf\n", head->id, head->name, head->gpa);
        }
        head = head->next;
    }
}

void pushback(node **head, char* id, char* name, double gpa){
    node *Newnode = Makenode(id, name, gpa);
    if (*head == NULL){
        *head = Newnode;
    }
    else
    {
        node *tmp = *head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = Newnode;
    }
}

int main(){
    node* head = NULL;
    int n; scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++){
        char id[101];
        fgets(id, sizeof(id), stdin);
        char name[101];
        fgets(name, sizeof(name), stdin);
        double gpa;
        scanf("%lf", &gpa);
        getchar(); 
        pushback(&head, id, name, gpa);
    }
    node* tmp = head;
    double max = 0;
    while(tmp != NULL){
        if (tmp->gpa > max){
            max = tmp->gpa;
        }
        tmp = tmp->next;
    }

    duyet_codk(head, max);
    

    tmp = head;
    while(tmp != NULL) {
        node* to_free = tmp;
        tmp = tmp->next;
        free(to_free);
    }
    
    return 0;
}
