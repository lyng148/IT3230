#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    int val;
    struct node *right;
    struct node *left;
} node;

node *Makenode(int val)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->val = val;
    Newnode->right = NULL;
    Newnode->left = NULL;
    return Newnode;
}

node *search(node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->val == val)
        return root;
    node *search_left = search(root->left, val);
    node *search_right = search(root->right, val);
    if (search_left)
        return search_left;
    return search_right;
}

bool exist(node *root, int val)
{
    if (root)
    {
        if (root->val == val)
            return true;
        bool check_left = exist(root->left, val);
        bool check_right = exist(root->right, val);
        return check_left || check_right;
    }
}

void addLeft(node *root, int u, int v)
{
    if (root)
    {
        if (exist(root, u) || !exist(root, v))
            return;
    }
    node *node_to_add = search(root, v);
    if (node_to_add == NULL) return;
    if (node_to_add->left != NULL)
        return;
    node *Newnode = Makenode(u);
    node_to_add->left = Newnode;
    return;
}

void addRight(node *root, int u, int v)
{
    if (root)
    {
        if (exist(root, u) || !exist(root, v))
            return;
    }
    node *node_to_add = search(root, v);
    if (node_to_add == NULL) return;
    if (node_to_add->right != NULL)
        return;
    node *Newnode = Makenode(u);
    node_to_add->right = Newnode;
    return;
}

void preorder(node *root)
{
    if (root)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root)
    {
        postorder(root->right);
        postorder(root->left);
        printf("%d ", root->val);
    }
}

int main()
{
    char choice[10];
    node *root = NULL;
    int u, v;
    
    while (1)
    {
        scanf(" %s", choice);
       
        if (strcmp(choice, "*") == 0)
            break;
            
        if (strcmp(choice, "MakeRoot") == 0)
        {
            scanf(" %d", &u);
            root = Makenode(u);
            continue;
        }

        if (strcmp(choice, "AddLeft") == 0)
        {
            scanf(" %d", &u);
            scanf(" %d", &v);
            addLeft(root, u, v);
            continue;
        }

        if (strcmp(choice, "AddRight") == 0)
        {
            scanf(" %d", &u);
            scanf(" %d", &v);
            addRight(root, u, v);
            continue;
        }

        if (strcmp(choice, "PreOrder") == 0)
        {
            preorder(root);
            printf("\n");
            continue;
        }

        if (strcmp(choice, "InOrder") == 0)
        {
            inorder(root);
            printf("\n");
            continue;
        }

        if (strcmp(choice, "PostOrder") == 0)
        {
            postorder(root);
            printf("\n");
            continue;
        }
        
    }
    return 0;
}