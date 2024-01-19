#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
} node;

node* makenode(int val)
{
    node* Newnode = (node*)malloc(sizeof(node));
    Newnode->val = val;
    Newnode->left = NULL;
    Newnode->right = NULL;
    return Newnode;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

node* insert(node *root, int val)
{
    if (root == NULL)
    {
        root = makenode(val);
    }
    else if (root->val <= val)
        root->right = insert(root->right, val);
    else root->left = insert(root->left, val);

    return root;
}

node* delete(node* root, int val)
{
    if (!root) return root;
    if (root)
    {
        if (root->val < val)
            root->right = delete(root->right, val);
        else if (root->val > val)
            root->left = delete(root->left, val);
        else
        {
            if (!root->left && !root->right) return NULL;
            else if (!root->left && root->right)
                return root->right;
            else if (!root->right && root->left)
                return root->left;
            else
            {
                // khi xoa node co ca 2 con, can tim thang nho nhat lon hon no theo thu tu InOrder => node trai nhat cua cay con ben phai
                node* tmp = root->right;
                while (tmp->left)
                    tmp = tmp->left;
                root->val = tmp->val;
                root->right = delete(root->right, root->val);
            }
        }
    }
    return root;
}

void InOrder(node* root)
{
    if (root)
    {
        InOrder(root->left);
        printf("%d ",root->val);
        InOrder(root->right);
    }
}

int Height(node* root)
{
    return !root ? 0 : max(Height(root->left), Height(root->right)) + 1;
}

int depth(node* root, int val, int level)
{
    if (root == NULL)
        return -1;
    if (root->val == val)
        return level;
    int downlevel = depth(root->left, val, level + 1);
    if (downlevel != -1)
        return downlevel;
    downlevel = depth(root->right, val, level + 1);
    return downlevel;
}

int main()
{
    node* root = makenode(1);
    insert(root, 2);
    insert(root, 31);
    insert(root, 33);
    insert(root, 32);
    insert(root, 34);
    InOrder(root);
    printf("\nDepth: %d\n", depth(root, 32, 0));
    printf("%d\n", Height(root));
    delete(root, 32);
    printf("\n%d\n", Height(root));
    InOrder(root);
}
