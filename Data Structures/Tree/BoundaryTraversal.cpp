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

bool isleaf(Node *root){
    if(!root->left && !root->right)
        return 1;
    return 0;
}

void addleft(Node *root, vector<int>&res){
    Node *curr=root->left;
    while(curr){
        if(!isleaf(curr))
            res.push_back(curr->key);
        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

void addright(Node *root, vector<int>&res){
    Node *curr=root->right;
    vector<int>tmp;
    while(curr){
        if(!isleaf(curr))
            tmp.push_back(curr->key);
        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }
        for(int i=tmp.size()-1; i>=0; i--)
            res.push_back(tmp[i]);
}

void addleaf(Node *root, vector<int>&res){
    if(isleaf(root)){
        res.push_back(root->key);
        return;
    }
        
    if(root->left)
        addleaf(root->left, res);
    if(root->right)
        addleaf(root->right, res);
}

vector<int> print(Node *root){
    vector<int>res;
    if(!root)
        return res;
    if(!isleaf(root))
        res.push_back(root->key);
    addleft(root,res);
    addleaf(root,res);
    addright(root,res);
    return res;
}
int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);
    
    vector<int>V=print(root);
    for(auto i : V)
        cout<<i<<" ";
	return 0;
}