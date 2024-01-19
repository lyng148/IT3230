#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 50000

typedef struct node
{
    int key;
    int value;
} node;

node *Makenode(int key, int value)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->key = key;
    Newnode->value = value;
    return Newnode;
}

int hashCode(int key)
{
    int r = key % SIZE;
    return r < 0 ? r + SIZE : r;
}

node *search(node **hashArr, int key)
{

    // Get the hashCode
    int hashIndex = hashCode(key);

    while (hashArr[hashIndex] != NULL)
    {
        if (hashArr[hashIndex]->key == key)
            return hashArr[hashIndex];
        hashIndex++;
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(node **hashArr, int key, int value)
{
    node *Newnode = Makenode(key, value);

    int hashIndex = hashCode(key);

    while (hashArr[hashIndex] != NULL && hashArr[hashIndex]->key != -1)
    {
        hashIndex++;
        // run in size of table
        hashIndex %= SIZE;
    }

    hashArr[hashIndex] = Newnode;
}

// delete function, return deleted node

node *deletee(node **hashArr, int key)
{
    int hashIndex = hashCode(key);
    while (hashArr[hashIndex] != NULL)
    {
        if (hashArr[hashIndex]->key == key)
        {
            node *tmp = hashArr[hashIndex];
            hashArr[hashIndex]->key = -1;
            hashArr[hashIndex]->value = -1;
            return tmp;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}
int main()
{
// Two sum problem
    int nums[] = {3, 3};
    int numsSize = 2;
    int target = 6;

    /* int *ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 2; */

    node *hashArr[SIZE];
    memset(hashArr, 0, sizeof(hashArr)); // Khởi tạo mảng hashArr bằng NULL
    for (int i = 0; i < numsSize; i++)
    {
        node* k = search(hashArr, target - nums[i]);
        if (k == NULL)
        {
            insert(hashArr, nums[i], i);
        }
        else
        {
            printf("%d %d", k->value, i);
            break;
        }
    }
}
