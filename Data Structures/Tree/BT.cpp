#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left,*right;

    //constructor
    Node(int v){
        val=v;
        left=right=NULL;
    }
};

int v;
Node *root = NULL;
int n;

void Display(Node * root){
    if (root != NULL){
		cout << root->val << "  ";
		Display(root->left);
		Display(root->right);
	}
}

void LevelOrderTraversal(Node * root){

}

int TotalNodes(Node * root){

}

int maxDepth(Node * root){

}

Node* Insert(int arr[], int i, int n){
    Node *root = nullptr;
    if (i < n){
		root = new Node(arr[i]);
       
        root->left = Insert(arr, 2*i + 1, n);
        root->right = Insert(arr,2*i + 2, n);
    }
    return root;
}

void insertFirstAvailable(Node* root, int value) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left == nullptr) {
            current->left = new Node(value);
            return;
        }
        else {
            q.push(current->left);
        }
        if (current->right == nullptr) {
            current->right = new Node(value);
            return;
        }
        else {
            q.push(current->right);
        }
    }
}

void Inorder(Node * root){

}

void Preorder(Node * root){

}

void Postorder(Node * root){

}

int main(){
	int usrchoice = 0;
	cin>>n;
	int *arr = new int[n];

	while (1)
	{
		cout << "\n\n1.Display\n2.Level Order Traversal\n3.Total Nodes\n4.Depth\n5.Insert\n6.Inorder\n7.Preorder\n8.Postorder\n9.Insert First Available\n10.Exit" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;

		switch (usrchoice){
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
			
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			root = Insert(arr,0,n);
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
			cin>>v;
			insertFirstAvailable(root,v);
			break;

		case 10:
			exit(1);

		default:
			cout << "Enter a valid choice : ";
			break;
		}
	}
	return 0;
}