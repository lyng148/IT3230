#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct TreeNode
{
    int value;
    struct TreeNode *rightChild;
    struct TreeNode *leftChild;
} TreeNode;


TreeNode *CreateTreeNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;
    return newNode;
}


TreeNode *FindNode(TreeNode *root, int value)
{
    if (!root)
        return NULL;
    if (root->value == value)
        return root;
    TreeNode *leftSearch = FindNode(root->leftChild, value);
    if (leftSearch)
        return leftSearch;
    return FindNode(root->rightChild, value);
}


bool ValueExists(TreeNode *root, int value)
{
    if (root)
    {
        if (root->value == value)
            return true;
        return ValueExists(root->leftChild, value) || ValueExists(root->rightChild, value);
    }
    return false;
}


void InsertLeft(TreeNode *root, int newValue, int parentValue)
{
    if (root && (!ValueExists(root, newValue) && ValueExists(root, parentValue)))
    {
        TreeNode *parent = FindNode(root, parentValue);
        if (parent && !parent->leftChild)
        {
            parent->leftChild = CreateTreeNode(newValue);
        }
    }
}


void InsertRight(TreeNode *root, int newValue, int parentValue)
{
    if (root && (!ValueExists(root, newValue) && ValueExists(root, parentValue)))
    {
        TreeNode *parent = FindNode(root, parentValue);
        if (parent && !parent->rightChild)
        {
            parent->rightChild = CreateTreeNode(newValue);
        }
    }
}


void PreorderTraversal(TreeNode *root)
{
    if (root)
    {
        printf("%d ", root->value);
        PreorderTraversal(root->leftChild);
        PreorderTraversal(root->rightChild);
    }
}


void InorderTraversal(TreeNode *root)
{
    if (root)
    {
        InorderTraversal(root->leftChild);
        printf("%d ", root->value);
        InorderTraversal(root->rightChild);
    }
}


void PostorderTraversal(TreeNode *root)
{
    if (root)
    {
        PostorderTraversal(root->leftChild);
        PostorderTraversal(root->rightChild);
        printf("%d ", root->value);
    }
}

int main()
{
    char command[10];
    TreeNode *root = NULL;
    int childValue, parentValue;

    while (true)
    {
        scanf(" %s", command);

        if (strcmp(command, "*") == 0)
            break;

        if (strcmp(command, "MakeRoot") == 0)
        {
            scanf(" %d", &childValue);
            root = CreateTreeNode(childValue);
            continue;
        }

        if (strcmp(command, "AddLeft") == 0)
        {
            scanf(" %d %d", &childValue, &parentValue);
            InsertLeft(root, childValue, parentValue);
            continue;
        }

        if (strcmp(command, "AddRight") == 0)
        {
            scanf(" %d %d", &childValue, &parentValue);
            InsertRight(root, childValue, parentValue);
            continue;
        }

        if (strcmp(command, "PreOrder") == 0)
        {
            PreorderTraversal(root);
            printf("\n");
            continue;
        }

        if (strcmp(command, "InOrder") == 0)
        {
            InorderTraversal(root);
            printf("\n");
            continue;
        }

        if (strcmp(command, "PostOrder") == 0)
        {
            PostorderTraversal(root);
            printf("\n");
            continue;
        }
    }
    return 0;
}
