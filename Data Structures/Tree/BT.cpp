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
			cout<<temp->val<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

int TotalNodes(Node * root){

}

int height(Node * root){
	if (root == NULL)
        return 0;
        
	int lh = height(root->left);
    int rh = height(root->right);
	
	return max(lh,rh) + 1;
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

//L Ro Ri

// void Inorder(Node * root){
// 	if(!root)
// 		return;
// 	Inorder(root->left);
// 	cout<<root->val<<" ";
// 	Inorder(root->right);
// }

void Inorder(Node* root){
	vector<int>inorder;
	stack<Node*>s;
	Node* temp=root;

	while(1){
		if(temp){
			s.push(temp);
			temp=temp->left;
		}
		else{
			if(s.empty())
				break;
			temp=s.top();
			s.pop();
			inorder.push_back(temp->val);
			temp=temp->right;
		}
	}
	for(auto i : inorder)
		cout<<i<<" ";
}

//Ro L Ri

// void Preorder(Node * root){
// 	if(!root)
// 		return;
// 	Preorder(root->left);
// 	cout<<root->val<<" ";
// 	Preorder(root->right);
// }

void Preorder(Node* root){
	vector<int>preorder;

	if(!root)
		return;

	stack<Node*>s;
	s.push(root);

	while(!s.empty()){
		root=s.top();
		s.pop();
		preorder.push_back(root->val);
		if(root->right)
			s.push(root->right);
		if(root->left)
			s.push(root->left);
	}
	for(auto i : preorder)
		cout<<i<<" ";
}


//L Ri Ro
// void Postorder(Node * root){
// 	if(!root)
// 		return;
// 	Postorder(root->left);
// 	cout<<root->val<<" ";
// 	Postorder(root->right);
// }

void Postorder(Node* root){
	if(!root)
		return;

	stack<Node*>s1,s2;
	s1.push(root);

	while(!s1.empty()){
		root=s1.top();
		s1.pop();
		s2.push(root);
		
		if(root->left)
			s1.push(root->left);
		if(root->right)
			s1.push(root->right);
	}
	while(!s2.empty()){
		cout<<s2.top()->val<<" ";
		s2.pop();
	}
}


int main(){
	int usrchoice = 0;
	cin>>n;
	int *arr = new int[n];

	while (1)
	{
		cout << "\n\n1.Display\n2.Insert\n3.Inorder\n4.Preorder\n5.Postorder\n6.Level Order Traversal\n7.Total Nodes\n8.Depth\n9.Insert First Available\n10.Exit" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;

		switch (usrchoice){
		case 1:
			Display(root);
			break;

		case 2:
			
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			root = Insert(arr,0,n);
			Display(root);
			break;

		case 3:
			Inorder(root); //L Ro Ri
			break;

		case 4:
			Preorder(root); //Ro L Ri
			break;

		case 5:
			Postorder(root);  // L Ri Ro
			break;

		case 6:
			LevelOrderTraversal(root);
			break;

		case 7:
			cout<<TotalNodes(root);
			break;

		case 8:
			cout<<height(root);
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