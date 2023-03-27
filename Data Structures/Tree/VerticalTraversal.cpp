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

vector<vector<int>> VerticalTraversal(Node *root){
    map<int, map<int, multiset<int>>> Nodes;
    queue<pair<Node*, pair<int,int>>> q;
    q.push({root, {0,0}});
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        Node* node=f.first;
        int x= f.second.first;
        int y= f.second.second;

        Nodes[x][y].insert(node->key);
        if(node->left)
            q.push({node->left, {x-1, y+1}});
        if(node->right)
            q.push({node->right, {x+1, y+1}});
    }

    vector<vector<int>> ans;
    for(auto p : Nodes){
        vector<int>col;
        for(auto t : p.second){
            col.insert(col.end(),t.second.begin(),t.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}


int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);
    
    vector<vector<int>>V=VerticalTraversal(root);
    for(auto i : V){
        cout<<"[";
        for(auto j : i){
            cout<<j<<",";
        }
        cout<<"]"<<" ";
    }
	return 0;
}