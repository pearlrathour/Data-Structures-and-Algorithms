// binary search tree
#include <iostream>
#include <queue>
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

void Display(Node *root){
	if (root != NULL){
		Display(root->left);
        cout << root->val << "  ";
		Display(root->right);
	}
}

void build(Node* root, int v) {
        while(1){
            if(root->val > v){
                if(!root->left){
                    Node* temp= new Node(v);
                    root->left=temp;
                    return;
                }
                else{
                    root=root->left;
                }  
            }
            else{
                if(!root->right){
                    Node* temp= new Node(v);
                    root->right=temp;
                    return;
                }
                else{
                    root=root->right;
                }  
            }
        }
    }
    
Node* bstFromPreorder(vector<int>& preorder) {
        Node* root= new Node(preorder[0]);
        
        for(int i=1; i<preorder.size(); i++){
            build(root,preorder[i]);
        }
        return root;
    }


int main(){
	int n;
    cin>>n;
    vector<int>preorder(n);
    for(int i=0; i<n; i++)
        cin>>preorder[i];
    Node* r=bstFromPreorder(preorder);
    Display(r);
	return 0;
}
