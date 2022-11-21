#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    
    Node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};


void Display(Node *root){
    if(root!=NULL){
        Display(root->left);
        cout<<root->key<<" ";
        Display(root->right);
    }
}

void LevelOrderTraversal(Node *root){

}

Node* TotalNodes(Node *root){

}

Node* maxDepth(Node *root){

}

Node *Insert(Node *root){
    cout<<"Enter value to be entered : ";
    int val;
    cin>>val;
    root=new Node(val);

    if(val==-1)
        return NULL;
    
    cout<<"Enter val to left of "<<val<<" : ";
    root->left=Insert(root->left);
    cout<<"Enter val to right of "<<val<<" : ";
    root->right=Insert(root->right);

    return root;
}

Node *Inorder(Node *root){
    if(root==NULL)
        return NULL;
    Display(root->left);
    cout<<root->key<<" ";
    Display(root->right);
}

Node *Preorder(Node *root){
    if(root==NULL)
        return NULL;
    cout<<root->key<<" ";
    Display(root->left);
    Display(root->right);
}

Node *Postorder(Node *root){
    if(root==NULL)
        return NULL;
    Display(root->left);
    Display(root->right);
    cout<<root->key<<" ";
}


int main()
{
	Node *root = NULL;
	int usrchoice = 0;

	while (1)
	{
		cout << "\n\n1.Display\n2.Level Order Traversal\n3.Total Nodes\n4.Depth\n5.Insert\n6.Inorder\n7.Preorder\n8.Postorder\n9.Exit" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;

		switch (usrchoice)
		{
		case 1:
			Display(root);
			break;

		case 2:
			LevelOrderTraversal(root);
			break;

		case 3:
			cout<<TotalNodes(root);
			break;

		case 4:
			cout<<maxDepth(root);
			break;

		case 5:
			root = Insert(root);
			Display(root);
			break;

		case 6:
			Inorder(root); //L Ro Ri
			break;

		case 7:
			Preorder(root); //Ro L Ri
			break;

		case 8:
			Postorder(root);  // L Ri Ro
			break;

		case 9:
			exit(1);

		default:
			cout << "Enter a valid choice : ";
			break;
		}
	}
	return 0;
}
