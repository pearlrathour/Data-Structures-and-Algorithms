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

void helper(Node* root, vector<string>& res, string r){
        if(!root)
            return;
        if(root->left||root->right)
            r+=(to_string(root->key) + "->");
        else{
            r+=(to_string(root->key));
            res.push_back(r);
        }
        helper(root->left,res,r);
        helper(root->right,res,r);  
}

vector<string> binaryTreePaths(Node* root) {
    vector<string> res;
    string r="";
    helper(root,res,r);
    return res;
}

int main(){
    Node *root = NULL;
    root=Insert(root);
    
    vector<string>V=binaryTreePaths(root);
    for(auto i : V){
        cout<<i<<",  ";
    }
	return 0;
}