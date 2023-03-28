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

vector<int> TopView(Node* root){
    vector<int>res;
    if(!root)
        return res;

    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        Node* node=f.first;
        int line=f.second;
            
        mp[line]=node->key;
        
        if(node->left)
            q.push({node->left,line-1});
        if(node->right)
            q.push({node->right,line-1});
    }
    for(auto i : mp)
        res.push_back(i.second);
    
    return res;
}


int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);
    
    vector<int>V=TopView(root);
    for(auto i : V){
        cout<<i<<" ";
    }
	return 0;
}