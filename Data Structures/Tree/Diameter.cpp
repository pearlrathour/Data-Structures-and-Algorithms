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

int height(Node* root,int &diameter){
    if (root == NULL)
        return 0;
        
	int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);
	diameter=max(diameter,lh+rh);
	return max(lh,rh) + 1;
}

int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);
    
    int diameter=0;
	height(root,diameter);
	cout<<diameter<<endl;
	return 0;
}