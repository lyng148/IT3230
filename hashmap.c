//----------------------------------------------------------
//-IMPORTANT: DON'T KNOW WHY, BUT IT CAN ONLY RUN AT LOCAL -
//-CAN'T RUN ON LEETCODE                                   -
//-NEED SOMETHING TO REPLACE AND FIX                       -
//---------------------------------------------------------- 







// In this hashmap function, we will use Linked list to store data has collision
// key can change to different data type like char*, double, etc.

/* Explanation:
- insertion: Inserts the key-value pair at the head of a linked list which is present at the given bucket index.
- hashFunction: Gives the bucket index for the given key. Our hash function = ASCII value of character * primeNumberx. The prime number in our case is 31 and the value of x is increasing from 1 to n for consecutive characters in a key.
- deletion: Deletes key-value pair from the hash table for the given key. It deletes the node from the linked list which holds the key-value pair.
- Search: Search for the value of the given key.
This implementation does not use the rehashing concept. It is a fixed-sized array of linked lists.
Key and value both are int in the given example. */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10007

// Linked list node, with data based on each problem
typedef struct node
{
    int key;
    int value;
    struct node *next;
} node;

// Constructor function, return a node
node *createNode(int key, int value)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->key = key;
    Newnode->value = value;
    Newnode->next = NULL;
    return Newnode;
}

// hashMap struct
typedef struct hashMap
{

    // hashMap contain number of elements in it
    // and it's capacity
    int numsOfElements, capacity;

    // hashMap is a 2d array contains node so that it can deal with collision
    node **arr;
} hashMap;

// Contructor with default capacity in #define
hashMap *createHashMap()
{
    hashMap *mp = (hashMap *)malloc(sizeof(hashMap));
    // Default capacity in this case (can be modified with header #define)
    mp->capacity = SIZE;
    mp->numsOfElements = 0;

    // Create arr with size of each hashValue = 1 by default (will increase if collision occor)
    mp->arr = (node **)malloc(mp->capacity * sizeof(node *));
    return mp;
}

// hashFunction return bucketIndex of key after hashing
int hashFuntion(hashMap *mp, int key)
{
    int bucketIndex;
    // We use hashMap's capacity to hash
    // It's recommend to use prime number like 1007, 100007,...
    // Because It's can avoid collision more than normal number.

    bucketIndex = key % mp->capacity;
    return bucketIndex;
}
//--------------------------------------
//-Use this function for Hashing string-
//--------------------------------------

/* int hashFunction(struct hashMap *mp, char *key)
{
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++)
    {

        // sum = sum + (ascii value of
        // char * (primeNumber ^ x))...
        // where x = 1, 2, 3....n
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;

        // factor = factor * prime
        // number....(prime
        // number) ^ x
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }

    bucketIndex = sum;
    return bucketIndex;
} */

void insert(hashMap *mp, int key, int value)
{
    // Getting bucket index for key - value pair
    int bucketIndex = hashFuntion(mp, key);

    // Creating new node with key and value
    node *Newnode = createNode(key, value);

    // Bucket index is empty => No collision
    if (mp->arr[bucketIndex] == NULL)
    {
        mp->arr[bucketIndex] = Newnode;
        return;
    }

    // Collision
    else
    {
        // Add Newnode to head of the linkded list which
        // present at bucketIndex
        Newnode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = Newnode;
        return;
    }
    return;
}

void deletee(hashMap *mp, int key)
{
    // Getting bucketIndex for the given key
    int bucketIndex = hashFuntion(mp, key);

    // To delete a node in a linked list, we will use two temp node
    // Prev and Current, if we find current node to delete, will will use
    // Prev to link Current->next
    node *prev = NULL;
    node *curr = mp->arr[bucketIndex];
    /* if (key == curr->key)
         {
             // We have two case when delete a node
             // First: the node to delete is head of linked list
             // Second: other else
             // In first case, we will set the mp->arr[bucketIndex] = NULL
             // In second case, we will run through the node until we find the node to delete
             // After found it, we will set prev->next = Curr->next

         } */
    if (curr->key == key)
    {
        mp->arr[bucketIndex] = curr->next;
        // We must use curr = curr->next here because it can handle
        // all case, whether curr->next is NULL or a node
        return;
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->key == key)
            {
                prev->next = curr->next;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return;
}

int search(hashMap *mp, int key)
{
    int bucketIndex = hashFuntion(mp, key);

    node *bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL)
    {
        if (bucketHead->key == key)
        {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }

    return -1;
}

int main()
{
    int nums[] = {1, 6, 6, 7};
    int target = 12;
    int numsSize = 4;

    hashMap *map = createHashMap();
    int *ans = (int *)malloc(2 * sizeof(int));
    memset(ans, 0, 2);
    int returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        int k = search(map, target - nums[i]);
        if (k == -1) 
        {
            insert(map, nums[i], i);
        }
        else
        {
            ans[0] = k;
            ans[1] = i;
        }
    }

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}