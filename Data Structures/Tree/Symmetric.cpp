#include <bits/stdc++.h>
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

bool isSymmetric(Node *l, Node *r){
    if(!l && !r)
        return 1;
    if(!l || !r)
        return l==r;
    if(l->key != r->key)
        return 0;
    return isSymmetric(l->left,r->right) && isSymmetric(l->right,r->left);
}

bool Symmetric(Node *root){
    return !root || isSymmetric(root->left,root->right);
}


int main(){
    Node *root = NULL;
    root=Insert(root);
    cout<<Symmetric(root);
	return 0;
}