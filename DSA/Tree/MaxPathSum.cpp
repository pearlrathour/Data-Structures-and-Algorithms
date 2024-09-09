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

int MaxPathSum(Node *root, int &maxsum){
    if(!root)
        return 0;
    int left=max(0,MaxPathSum(root->left,maxsum));
    int right=max(0,MaxPathSum(root->right,maxsum));
    maxsum= max(maxsum, left+ right+ root->key);
    return max(left,right) + root->key;
}

int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);
    MaxPathSum(root,maxsum);
    cout<<maxsum<<endl;
	return 0;
}