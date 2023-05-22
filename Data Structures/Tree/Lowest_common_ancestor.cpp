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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root || root==p || root==q)
            return root;
        Node* left= lowestCommonAncestor(root->left, p, q);
        Node* right= lowestCommonAncestor(root->right, p, q);
        
        if(!left)
            return right;
        else if(!right)
            return left;
        else
            return root;
    }


int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);
    
    cout<<lowestCommonAncestor(root,p,q)<<endl;
	return 0;
}