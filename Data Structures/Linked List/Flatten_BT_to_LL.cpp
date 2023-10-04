#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *left, *right;

	// Constructor
	Node(int k){
		val = k;
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

void Display(Node * root){
    if (root != NULL){
		cout << root->val << "  ";
		Display(root->left);
		Display(root->right);
	}
}

void flatten(Node* root) {
    Node *curr=root, *pre;

    while(curr){
        if(curr->left){
            pre=curr->left;

            while(pre->right)
                pre=pre->right;

            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr=curr->right;   
        }
    }


int main(){
    Node *root = NULL;
    int maxsum=INT_MIN;
    root=Insert(root);

    flatten(root);
    Display(root);
	return 0;
}