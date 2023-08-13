// binary search tree
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;

	// Constructor
	Node(int k){
		key = k;
		left = right = NULL;
	}
};

void Display(Node *root)
{
	if (root != NULL){
		cout << root->key << "  ";
		Display(root->left);
		Display(root->right);
	}
}

//Breadth First Traversal
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

int height(Node* root,int &diameter){
    if (root == NULL)
        return 0;
        
	int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);
	diameter=max(diameter,lh+rh);
	return max(lh,rh) + 1;
}

int lheight(Node* root){
    int ht = 0;
    while(root){
        ht++;
        root=root->left;
    }
    return ht;
}
  
int rheight(Node* root){
    int ht = 0;
    while(root){
        ht++;
        root=root->right;
    }
    return ht;
}

int TotalNodes(Node* root){
    if (root == NULL)
        return 0;
    int lh = lheight(root);
    int rh = rheight(root);

    // If left and right heights are equal return 2^h(1<<h) -1
    if (lh == rh)
        return (1 << lh) - 1;
    
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}

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

//Recursive
// void Inorder(Node *root){
// 	if(root==NULL)
// 		return;
	
// 	Inorder(root->left);
// 	cout<<root->key<<" ";
// 	Inorder(root->right);
// }


//Iterative
void Inorder(Node *root){
	vector<int>Inorder;
	stack<Node*>s;
	Node *temp=root;

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
			Inorder.push_back(temp->key);
			temp=temp->right;
		}
	}
	for(auto i : Inorder){
		cout<<i<<" ";
	}
}

//Recursive
// void Preorder(Node * root){
// 	if(root==NULL)
// 		return;
	
// 	cout<<root->key<<" ";
// 	Preorder(root->left);
// 	Preorder(root->right);
// }

//Iterative
void Preorder(Node *root){
	vector<int>preorder;
	if(root == NULL)
		return ;
	
	stack<Node*>s;
	s.push(root);
	while(!s.empty()){
		root = s.top();
		s.pop();
		preorder.push_back(root->key);
		if(root->right){
			s.push(root->right);
		}
		if(root->left){
			s.push(root->left);
		}
	}
	for(auto i : preorder){
		cout<<i<<" ";
	}
}

// void Postorder(Node *root){
// 	if(root==NULL)
// 		return;
	
// 	Postorder(root->left);
// 	Postorder(root->right);
// 	cout<<root->key<<" ";
// }


//Iterative
// 2 stack
// void Postorder(Node *root){
// 	if(!root)
// 		return ;

// 	stack<Node*>s1,s2;
// 	s1.push(root);

// 	while(!s1.empty()){
// 		root=s1.top();
// 		s1.pop();
// 		s2.push(root);

// 		if(root->left)
// 			s1.push(root->left);

// 		if(root->right)
// 			s1.push(root->right);
// 	}
// 	while(!s2.empty()){
// 		cout<<s2.top()->key<<" ";
// 		s2.pop();
// 	}
// }


// 1 stack
void Postorder(Node *root){
	if(!root)
		return ;

	stack<Node*>s;
	vector<int>postorder;
	Node *curr=root,*temp=NULL;

	while(curr || !s.empty()){
		if(curr){
			s.push(curr);
			curr=curr->left;
		}
		else{
			curr=s.top();
			if(!curr->right || curr->right==temp){
				postorder.push_back(curr->key);
				s.pop();
				temp=curr;
				curr=NULL;
			}
			else{
				curr=curr->right;
			}
		}
	}
	for(auto i : postorder){
		cout<<i<<" ";
	}
	
}

int main()
{
	Node *root = NULL;
	int usrchoice = 0, diameter=0;
	vector<vector<int>>V;

	while (1)
	{
		cout << "\n\n1.Display\n2.Insert\n3.Inorder\n4.Preorder\n5.Postorder\n6.Level Order Traversal\n7.Height\n8.Diameter\n9.Total Nodes\n10.Exit\n" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;

		switch (usrchoice)
		{
		case 1:
			Display(root);
			break;

		case 2:
			root = Insert(root);
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
			cout<<height(root,diameter);
			break;

		case 8:
			diameter=0;
			height(root,diameter);
			cout<<diameter<<endl;
			break;
		
		case 9:
			cout<<TotalNodes(root);
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
