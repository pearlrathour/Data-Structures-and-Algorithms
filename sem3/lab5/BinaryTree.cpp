// binary search tree
#include <iostream>
using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *insert(struct node *node, int key){

	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

struct node *minValueNode(struct node *node)
{
	struct node *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct node *deleteNode(struct node *root, int key)
{

	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{

		if (root->left == NULL and root->right == NULL)
			return NULL;

		else if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		struct node *temp = minValueNode(root->right);

		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main()
{
	struct node *root = NULL;
	// root = insert(root, 50);
	int number;
	int cont = 1;
	while (cont)
	{
		cout << " " << endl;
		cout << "do you wish to A: insert a node B: delete a node?" << endl;
		char wish;
		cin >> wish;
		if (wish == 'A' || wish == 'a')
		{
			cout << "what number you wish to insert?" << endl;
			// inorder(root);
			cout << " " << endl;
			cin >> number;
			root = insert(root, number);
		}
		else if (wish == 'B' || wish == 'b')
		{
			if (root == NULL)
			{
				cout << "empty tree" << endl;
			}
			else
			{
				cout << "what number you wish to delete?" << endl;
				inorder(root);
				cout << " " << endl;
				cin >> number;
				root = deleteNode(root, number);
			}
		}
		else
		{
			cout << "wrong input" << endl;
		}
		cout << "press Y if you want to continue the operation" << endl;
		char yes;
		cin >> yes;
		if (yes != 'y')
		{
			cont = 0;
		}
		cout << "inorder expression" << endl;
		inorder(root);
		cout << " " << endl;
	}

	return 0;
}
