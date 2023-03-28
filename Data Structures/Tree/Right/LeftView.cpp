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

//Recursive
// T.C-O(N) S.C-O(H)
void RightView(Node* root, int level, vector<int>&res){
    if(!root)
        return;

    //Reverse Preorder

    if(res.size()==level)
        res.push_back(root->key);
    RightView(root->right,level+1,res);
    RightView(root->left,level+1,res);
}


int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);
    
    vector<int>V;
    RightView(root,0,V);
    for(auto i : V){
        cout<<i<<" ";
    }
	return 0;
}