// binary search tree
#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int key;
	Node *left, *right;

	// Constructor
	Node(int k){
		key = k;
		left = right = NULL;
	}
};

void Display(Node *root){
	if (root != NULL){
		Display(root->left);
        cout << root->key << "  ";
		Display(root->right);
	}
}

//O(logn) - O(n)
Node *Insert(Node *root,int val){
	Node *temp=new  Node(val);
    if(root==NULL)
        return temp;
    if(val < root->key)
        root->left=Insert(root->left,val);
    else
        root->right=Insert(root->right,val);
    return root;
}

Node *minValueNode(Node *node) {
  Node *curr= node;

  // Find the leftmost leaf
  while (curr && curr->left != NULL)
  	curr = curr->left;

  return curr;
}

//O(logn) - O(n)
Node *Delete(Node *root,int val){
	if (root == NULL)
		return root;

  	if (val < root->key)
    	root->left = Delete(root->left, val);
  	else if (val > root->key)
    	root->right = Delete(root->right, val);
  	else{
    	// If the node is with only one child or no child
		if (root->left == NULL){
			Node *temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			delete(root);
			return temp;
		}

		// If the node has two children 
		Node*temp = minValueNode(root->right);

		// Place the inorder successor in position of the node to be deleted
		root->key = temp->key;

		// Delete the inorder successor
		root->right = Delete(root->right, temp->key);
  }
  return root;
}


int main(){
	Node *root = NULL;
	int usrchoice = 0;
    int val;

	while (1){
		cout << "\n\n1.Display  2.Insert  3.Delete  4.Exit" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;

		switch (usrchoice){

		case 1:
			Display(root);
			break;

		case 2:
            cout<<"Enter value : ";
            cin>>val;
			root= Insert(root,val);
			Display(root);
			break;

		case 3:
			cout<<"Enter value : ";
            cin>>val;
			root=Delete(root,val);
            Display(root);
            break;

		case 4:
			exit(1);

		default:
			cout << "Enter a valid choice : ";
			break;
		}
	}
	return 0;
}
