// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left,*right;
	int height;

    Node(int val){
	key=val;
	left=right=NULL;
    height = 1;
    }
};

int height(Node *N){
	if(N == NULL)
		return 0;
	return N->height;
}


int max(int a, int b){
	return (a > b)? a : b;
}


Node *rightRotate(Node *y){
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;
	// Return new root
	return x;
}


Node *leftRotate(Node *x){
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;
	// Return new root
	return y;
}

int getBalance(Node *N){
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key){
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(new Node(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height= 1 + max(height(node->left) , height(node->right));

	/* 3. Get the balance factor of this ancestor node*/
	int balance = getBalance(node);

	// If this node becomes unbalanced, then 4 cases are-

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}


Node * minValueNode(Node* node) { 
    Node* curr=node; 
    //leftmost leaf
    while (curr->left != NULL) 
        curr = curr->left; 
  
    return curr; 
} 

Node* deleteNode(Node* root, int key) {  
    //1:BST DELETE 
    if (root == NULL) 
        return root; 

    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
  
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
  
    //key==root->key
    else{ 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ){ 
            Node *temp = root->left ? root->left : root->right; 
  
            // No child case 
            if (temp == NULL){ 
                temp = root; 
                root = NULL; 
                delete root;
            } 

            // One child case 
            else{
                *root = *temp; 
                free(temp); 
            } 
        }

    else{ 
        // node with two children: Get the inorder successor (smallest in the right subtree) 
        Node* temp = minValueNode(root->right); 
  
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key); 
        } 
    } 
    
    if (root == NULL) 
    return root; 
  
    //2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left),height(root->right)); 
  
    //3: GET THE BALANCE FACTOR OF this node
    int balance = getBalance(root); 
  
    // Left Left Case 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && getBalance(root->left) < 0){ 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && getBalance(root->right) > 0) { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
} 

void preOrder(Node *root){
	if(root != NULL){
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){
	Node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	cout << "Preorder traversal of the constructed AVL tree is \n";
	preOrder(root);

    root = deleteNode(root, 10); 
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n"; 
    preOrder(root); 
	return 0;
}