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

vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>>res;
        if(!root)
            return res;
        
        queue<Node *>q;
        q.push(root);
        bool ltor=1;
        Node *curr;
        int qsize,j;
        
        while(!q.empty()){
            qsize=q.size();
            vector<int>v;
            for(int i=0; i<qsize; i++){
                curr=q.front();
                q.pop();
                v.push_back(curr->key);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(ltor)
                res.push_back(v);
            else{
                reverse(v.begin(),v.end());
                res.push_back(v);
            }
            ltor=!ltor;
        }
    return res;
}

int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);

    vector<vector<int>>V=zigzagLevelOrder(root);
	for(auto x : V){
		cout<<"[";
		for(int j : x)
			cout<<j<<",";
		cout<<"]"<<" ";
	};
	return 0;
}