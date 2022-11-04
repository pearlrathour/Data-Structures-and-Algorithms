// binary search tree
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;

	// Constructor
	Node(int k){
		key = k;
		left = right = NULL;
	}
};

void Display(Node *root)
{
	if (root != NULL){
		Display(root->left);
		cout << root->key << "  ";
		Display(root->right);
	}
}

void LevelOrderTraversal(Node *root){
	queue<Node *>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}

			else{
				cout<<temp->key<<" ";
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
			}
		}
	}
}

int maxDepth(Node* root){
	int depth;
    if (root == NULL)
        return 0;
    else {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        if (lDepth > rDepth)
            depth=lDepth + 1;
        else
            depth=rDepth + 1;
    }
	return depth;
}

Node *Insert(Node *root){
	cout<<"Enter value to be entered : ";
	int val;
	cin>>val;
	root=new Node(val);

	if(val==-1)
		return NULL;

	cout<<"Enter value to left of "<<val<<" : ";
	root->left=Insert(root->left);
	cout<<"Enter value to right of "<<val<<" : ";
	root->right=Insert(root->right);

	return root;
}

void Inorder(Node *root){
	if(root==NULL)
		return;
	
	Inorder(root->left);
	cout<<root->key<<" ";
	Inorder(root->right);
}

void Preorder(Node * root){
	if(root==NULL)
		return;
	
	cout<<root->key<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(Node *root){
	if(root==NULL)
		return;
	
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->key<<" ";
}


int main()
{
	Node *root = NULL;
	int usrchoice = 0;

	while (1)
	{
		cout << "\n\n1.Display\n2.Level Order Traversal\n3.Depth\n4.Insert\n5.Inorder\n6.Preorder\n7.Postorder\n8.Exit" << endl;
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
			cout<<maxDepth(root);
			break;

		case 4:
			root = Insert(root);
			Display(root);
			break;

		case 5:
			Inorder(root); //L Ro Ri
			break;

		case 56:
			Preorder(root); //Ro L Ri
			break;

		case 7:
			Postorder(root);  // L Ri Ro
			break;

		case 8:
			exit(1);

		default:
			cout << "Enter a valid choice : ";
			break;
		}
	}
	return 0;
}
