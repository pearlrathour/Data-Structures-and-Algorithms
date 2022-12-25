// binary search tree
#include <bits/stdc++.h>
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

int height(Node *root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}

int main()
{
	Node *root = NULL;
    root = Insert(root);
    cout<<height(root) - 1;
	return 0;
}