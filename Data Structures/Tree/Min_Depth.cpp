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

//DFS
int minDepth_dfs(Node* root) {
        if(!root)
            return 0;

        if(!root->left && !root->right)
            return 1;
    
        if(!root->left)
            return minDepth_dfs(root->right) + 1;

        if(!root->right)
            return minDepth_dfs(root->left) + 1;

        return min(minDepth_dfs(root->left), minDepth_dfs(root->right)) +1;  
    }

//BFS
int minDepth_bfs(Node* root){
        if(!root)
            return 0;
        
        int d=0;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            d++;
            int size=q.size();
            while(size--){
                Node* curr = q.front(); 
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (!curr->left && !curr->right) {
                    return d;
                }
            }
        }
        return d;
    }

int main(){
    Node *root = NULL;
    root=Insert(root);

    cout<<minDepth_bfs(root);
	return 0;
}