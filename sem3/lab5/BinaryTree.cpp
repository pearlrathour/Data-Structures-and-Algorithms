//Implement a binary tree and any traversal technique

//Implimenttaion of queue using Linked List

#include <iostream>
using namespace std;

// Structure of each node of the tree
struct Node{
	int data;
	struct node* left;
	struct node* right;

    // Val is the key or the value that
    // has to be added to the data part
    Node(int val){
        data = val;
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

Node *Insert(Node *node, int val){
    // If BST doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if(node == NULL)
    {
        node = new Node;
        node->Key = key;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
    }
    // If the given key is greater than
    // node's key then go to right subtree
    else if(node->key < key){
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }
    // If the given key is smaller than
    // node's key then go to left subtree
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }



void display( ){
    
}

int main(){
    int usrchoice=0;
    int val, k;

    while (1){
        cout << "\n\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n"<< endl;
        cout << "Enter the choice of operation to be implemented : ";
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            
            break;

        case 2:
            
            break;

        case 3:
            
            break;

        case 4:
             exit(1);

        default:
            cout<<"Enter a valid choice : ";
            break;
           
        }
    }
    return 0;
}