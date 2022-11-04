// binary search tree
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;

	// Constructor
	Node(int k)
	{
		key = k;
		left = right = NULL;
	}
};

void Display(Node *root)
{
	if (root != NULL)
	{
		cout << root->key << "  ";
		Display(root->left);
		Display(root->right);
	}
}

void LevelOrderTraversal(Node *root)
{
	queue<Node *> q;
	q.push(root);
	q.push(NULL); // end of 1st level

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}

		else
		{
			cout << temp->key << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}

Node *Insert(Node *root)
{
	cout << "Enter Value to be entered : ";
	int val;
	cin >> val;
	root = new Node(val);

	if (val == -1)
		return NULL;

	cout << "Enter val to left of " << val << " : " << endl;
	root->left = Insert(root->left);
	cout << "Enter val to right of " << val << " : " << endl;
	root->right = Insert(root->right);

	return root;
}

void Inorder(Node *root)
{
	if (root == NULL)
		return;

	Inorder(root->left);
	cout << root->key << " ";
	Inorder(root->right);
}

void Preorder(Node *root)
{
	if (root == NULL)
		return;

	cout << root->key << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(Node *root)
{
	if (root == NULL)
		return;

	Postorder(root->left);
	Postorder(root->right);
	cout << root->key << " ";
}

int main()
{
	Node *root = NULL;
	int usrchoice = 0;
	int val;

	while (1)
	{
		cout << "\n\n1.Display\n2.Level Order Traversal\n3.Insert\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;

		switch (usrchoice)
		{
		case 1:
			Display(root);
			break;

		case 2:
			LevelOrderTraversal(root);
			break;

		case 3:
			root = Insert(root);
			Display(root);
			break;

		case 4:
			Inorder(root); // L Ro Ri
			break;

		case 5:
			Preorder(root); // Ro L Ri
			break;

		case 6:
			Postorder(root); // L Ri Ro
			break;

		case 7:
			exit(1);
			break;

		default:
			cout << "Enter a valid choice : ";
			break;
		}
	}
	return 0;
}
