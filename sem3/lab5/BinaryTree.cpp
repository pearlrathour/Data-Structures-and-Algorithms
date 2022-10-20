#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define vec vector<ll>
#define pb push_back
#define MIN INT_MIN
#define MAX INT_MAX

using namespace std; 

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* new_node=new Node;
	if(!new_node){
		cout<<"OVERFLOW\n";
		return NULL;
	}
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

Node* Insert(Node* root, int data){
	if(root==NULL){
		root=createNode(data);
		return root;
	}
	queue<Node*> Q;
	Q.push(root);

	while(!Q.empty()){
		Node* temp=Q.front();
		Q.pop();
		if(temp->left!=NULL)
			Q.push(temp->left);
		else{
			temp->left=createNode(data);
			return root;
		}

		if(temp->right!=NULL){
			Q.push(temp->right);
		}
		else{
			temp->right=createNode(data);
			return root;
		}
	}
}

void InOrder(Node* root)  //left-root-right (sorted order)
{
	if(root==NULL)
		return;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}
int main()
{
	Node *root=NULL;
	
	int n,num;
    cout<<"Enter number of elements : ";
	cin>>n; //no of elements to be inserted
	for(int i=0;i<n;i++)
	{
		cin>>num;
		root=Insert(root,num);
	}
	InOrder(root);
}