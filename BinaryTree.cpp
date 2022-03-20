#include <iostream>

struct Node
{
	int data;
	Node *left, *right;
};

int height(Node *root)
{
	if (root == NULL)
		return -1;
	
	int lHeight = height(root->left);
	int rHeight = height(root->right);

	if (lHeight > rHeight)
		return lHeight + 1;
	else
		return rHeight + 1;
}

int countLeaf(Node *root)
{
	if (root == NULL)
		return 0;
	else if (!root->left && !root->right)
		return 1;
	else
		return countLeaf(root->left) + countLeaf(root->right);
}

int count(Node *root)
{
	if (root == NULL)
		return 0;

	return count(root->left) + count(root->right) + 1;
}

void printCurrentLevel(Node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 0)
		printf("%d ", root->data);
	else
	{
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

void printLevelOrder(Node *root)
{
	int h = height(root);

	for (int i = 0; i <= h; i++)
	{
		printCurrentLevel(root, i);
		std::cout << std::endl;
	}
}

Node *newNode(int data)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = data;
	n->left = n->right = NULL;
	
	return n;
}

void invert(Node *root)
{
	if (root == NULL)
		return;

	Node *temp = root->left;
	root->left = root->right;
	root->right = temp;

	invert(root->left);
	invert(root->right);
}

int main()
{
	Node *n = newNode(1);
	n->left = newNode(2);
	n->right = newNode(3);
	n->left->left = newNode(4);
	n->right->left = newNode(5);
	n->right->right = newNode(6);
	n->right->left->left = newNode(7);
	n->right->left->left->left = newNode(8);
	n->right->left->left->right = newNode(9);

	printLevelOrder(n);
	std::cout << std::endl;
	invert(n);
	printLevelOrder(n);

	//std::cout << countLeaf(n);

	return 0;
}
