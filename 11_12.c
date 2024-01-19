#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;

int max(int a, int b) { return a > b ? a : b; };

node *Makenode(int val)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->val = val;
    Newnode->left = NULL;
    Newnode->right = NULL;
    return Newnode;
}

node *insertIntoBST(node *root, int val)
{
    node *Newnode = Makenode(val);
    if (root == NULL)
    {
        root = Newnode;
        return root;
    }
    node *start = root;
    node *prev = root;
    while (root != NULL)
    {
        if (root->val < Newnode->val)
        {
            prev = root;
            root = root->right;
        }
        else if (root->val > Newnode->val)
        {
            prev = root;
            root = root->left;
        }
    }
    if (prev->val > Newnode->val)
    {
        prev->left = Newnode;
    }
    if (prev->val < Newnode->val)
    {
        prev->right = Newnode;
    }
    return start;
}

node *deleteNode(node *root, int key)
{
    if (!root)
        return root;
    if (root)
    {
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else
        {
            // case 1:
            if (!root->left && !root->right)
                return NULL;
            // case 2:
            if (!root->left && root->right)
            {
                return root->right;
            }
            // case 3:
            if (!root->right && root->left)
            {
                return root->left;
            }
            // case 4:
            node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
        }
    }
    return root;
}

node *search(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        return root;
    }
    if (val < root->val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

node *findmin(node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

node *findmax(node *root)
{
    while (root->right)
        root = root->right;
    return root;
}

void inra(node *root)
{
    if (root)
    {
        inra(root->left);
        printf("%d ", root->val);
        inra(root->right);
    }
}

int height(node *root)
{
    return (!root) ? 0 : max(height(root->left), height(root->right)) + 1;
}

int depth(node *root, int val) {
    int depth = 0;
    while (root != NULL) {
        if (val > root->val) {
            root = root->right;
        } else if (val < root->val) {
            root = root->left;
        } else {
            return depth;
        depth++;
    }
    return -1; 
}


void freeTree(node *root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    node *root = NULL;
    char command[10];
    int value;

    while (1)
    {
        scanf("%s", command);

        if (strcmp(command, "#") == 0)
        {
            break;
        }

        if (strcmp(command, "Insert") == 0)
        {
            scanf("%d", &value);
            root = insertIntoBST(root, value);
        }
        else if (strcmp(command, "Delete") == 0)
        {
            scanf("%d", &value);
            if (!search(root, value))
            {
                printf("%d not found\n", value);
            }
            else
            {
                root = deleteNode(root, value);
            }
        }
        else if (strcmp(command, "Search") == 0)
        {
            scanf("%d", &value);
            node *found = search(root, value);
            printf(found ? "found %d\n" : "%d not found\n", value);
        }
        else if (strcmp(command, "FindMin") == 0)
        {
            if (!root)
            {
                printf("Tree is empty\n");
            }
            else
            {
                node *minNode = findmin(root);
                printf("Min is %d\n", minNode->val);
            }
        }
        else if (strcmp(command, "FindMax") == 0)
        {
            if (!root)
            {
                printf("Tree is empty\n");
            }
            else
            {
                node *maxNode = findmax(root);
                printf("Max is %d\n", maxNode->val);
            }
        }
        else if (strcmp(command, "PrintTree") == 0)
        {
            inra(root);
            printf("\n");
        }
        else if (strcmp(command, "TreeHeight") == 0)
        {
            printf("%d\n", height(root));
        }
        else if (strcmp(command, "Depth") == 0)
        {
            scanf("%d", &value);
            int d = depth(root, value);
            if (d != -1)
            {
                printf("%d\n", d);
            }
            else
            {
                printf("%d not found\n", value);
            }
        }
    }

    freeTree(root);
    return 0;
}
