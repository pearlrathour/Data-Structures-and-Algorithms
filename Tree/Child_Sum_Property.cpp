#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    // Constructor
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node *Insert(Node *root)
{
    cout << "Enter value to be entered : ";
    int val;
    cin >> val;
    root = new Node(val);

    if (val == -1)
        return NULL;

    cout << "Enter value to left of " << val << " : ";
    root->left = Insert(root->left);
    cout << "Enter value to right of " << val << " : ";
    root->right = Insert(root->right);

    return root;
}

void LevelOrderTraversal(Node *root){
	queue<Node *>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->key<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}
void reorder(Node* root){


}

void childsum(Node* root){
    if(!root)
        return;
    
    int child=0;
    if(root->left)
        child+=root->left->key;
    if(root->right)
        child+=root->right->key;

    if(child >= root->key)
        root->key=child;
    else{
        if(root->left)
            root->left->key=root->key;
        else if(root->right)
            root->right->key=root->key;
    }

    reorder(root->left);
    reorder(root->right);

    int tot=0;
    if(root->left)
        tot+=root->left->key;
    if(root->right)
        tot+=root->right->key;
    if(root->left || root->right)
        root->key=tot;
}

int main()
{
    Node *root = NULL;
    root = Insert(root);
    LevelOrderTraversal(root);
    cout<<endl<<endl;

    childsum(root);
    LevelOrderTraversal(root);
    cout<<endl<<endl;
    return 0;
}