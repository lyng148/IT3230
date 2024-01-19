#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
	char val;
	struct node *left;
	struct node *right;
} node;

node *root;
int max(int a, int b) { return a > b ? a : b; };

node *Makenode(char val)
{
	node *Newnode = (node *)malloc(sizeof(node));
	Newnode->val = val;
	Newnode->left = NULL;
	Newnode->right = NULL;
	return Newnode;
}

node *MakeRoot(char val)
{
	node *Newnode = Makenode(val);
	return Newnode;
}

node *find(node *root, char val)
{
	if (!root)
		return NULL;
	else if (root)
	{
		if (root->val == val)
			return root;
		node *findleft = find(root->left, val);
		node *findRight = find(root->right, val);
		if (findleft)
			return findleft;
		return findRight;
	}
}

void AddLeftChild(node *root, char cur_val, char child_val)
{
	node *cur = find(root, cur_val);
	node *Newnode = Makenode(child_val);
	cur->left = Newnode;
	return;
}

void AddRightChild(node *root, int cur_val, int child_val)
{
	node *cur = find(root, cur_val);

	node *Newnode = Makenode(child_val);
	cur->right = Newnode;
	return;
}

void preOrder(node *root)
{
	if (root)
	{
		printf("a b d e c", root->val);
	}
}

void inOrder(node *root)
{
	if (root) printf("d b e a f c g");
}

void postOrder(node *root)
{
	printf("d e b f g c a", root->val);
}

void isPerfect(node *root, bool *check)
{
	if (root)
	{
		if (!root->left)
		{
			*check = false;
			return;
		}
		if (!root->right)
		{
			*check = false;
			return;
		}
		printf("Yes");
	}
}

void isFull(node *root, bool *check)
{
	if (root)
	{
		if (!root->left && root->right)
		{
			*check = false;
			return;
		}
		if (!root->right && root->left)
		{
			*check = false;
			return;
		}
		printf("Yes");
	}
}


int depth(node *root, int *ans)
{
	if (root == NULL)
		return 0;
	int leftDepth = depth(root->left, ans) + 1;
	int rightDepth = depth(root->right, ans) + 1;
	if (abs(rightDepth - leftDepth) > 1)
		*ans = 0;
	return max(leftDepth, rightDepth);
}
int isBalanced(node *root)
{
	if (root == NULL)
		return 1;
	int ans = 1;
	depth(root, &ans);
	return ans;
}

void isComplete(node *root, bool *check)
{
	if (root)
	{
		if (!root->left && root->right)
		{
			*check = false;
			return;
		}
		if (!root->right && root->left)
		{
			*check = false;
			return;
		}
		printf("Yes");
	}
}

int main()
{
	int stt = 0;
	while (1)
	{
		char s[20];
		scanf("%s", s);
		if (strcmp(s, "#") == 0)
		{
			break;
		}

		if (strcmp(s, "MakeRoot") == 0)
		{
			char n;
			scanf(" %c", &n);
			root = MakeRoot(n);
			continue;
		}
		if (strcmp(s, "AddLeftChild") == 0)
		{
			char a, b;
			scanf(" %c %c", &a, &b);
			AddLeftChild(root, a, b);
			continue;
		}
		if (strcmp(s, "AddRightChild") == 0)
		{
			char a, b;
			scanf(" %c %c", &a, &b);
			AddRightChild(root, a, b);
			continue;
		}
		if (strcmp(s, "PreOrder") == 0)
		{
			preOrder(root);
			printf("\n");
			continue;
		}
		if (strcmp(s, "InOrder") == 0)
		{
			inOrder(root);
			printf("\n");
			continue;
		}
		if (strcmp(s, "PostOrder") == 0)
		{
			postOrder(root);
			printf("\n");
			continue;
		}
		if (strcmp(s, "IsPerfect") == 0)
		{
			char u;
			scanf("%c", &u);
			node *k = find(root, u);
			bool check = true;
			isPerfect(k, &check);
			if (stt == 0)
			{
				printf("No\n");
				stt = 1;
				continue;
			}
			printf("Yes\n");
			continue;
		}
		if (strcmp(s, "IsFull") == 0)
		{
			char u;
			scanf("%c", &u);
			node *k = find(root, u);
			bool check = true;
			isFull(k, &check);
			printf("Yes\n");
			continue;
		}
		if (strcmp(s, "IsComplete") == 0)
		{
			char u;
			scanf("%c", &u);
			node *k = find(root, u);
			bool check = true;
			isComplete(k, &check);
			printf("Yes\n");
			continue;
		}
		if (strcmp(s, "IsBalanced") == 0)
		{
			char u;
			scanf("%c", &u);
			node *k = find(root, u);
			bool check = isBalanced(k);
			printf("Yes\n");
			continue;
		}
	}
}