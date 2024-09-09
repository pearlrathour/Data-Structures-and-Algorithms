#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int x){
        val=x;
        next=NULL;
    }
};

struct TreeNode{
    int val;
    TreeNode *left,*right;

    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};

Node *Insert(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL){
       temp->next=head;
       return temp; 
    }
    
    Node *curr=head;
    while(curr->next != NULL)
        curr=curr->next;
    curr->next=temp;
    temp->next=NULL;
    return head;
}

void print(Node *head){
    Node *curr=head;
    cout<<endl<<endl;
    while(curr != NULL){
        cout<<curr->val<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

void Display(TreeNode * root){
    if (root != NULL){
		cout << root->val << "  ";
		Display(root->left);
		Display(root->right);
	}
}

TreeNode* create(Node* head, Node* tail){
    if(head==tail)
        return NULL;

    Node *slow=head, *fast=head;
    while(fast!=tail && fast->next!=tail){
        slow=slow->next;
        fast=fast->next->next;
    }

    TreeNode *root= new TreeNode(slow->val);
    root->left= create(head,slow);
    root->right= create(slow->next,tail);
    return root;
}

int main(){
    Node *head=NULL;
    cout<<"Enter n: ";
    int n,v;
    cin>>n;
    cout<<"Enter nodes in List: \n";
    for(int i=0; i<n; i++){
        cin >> v;
        head=Insert(head,v);
    }
    print(head);
    TreeNode* root=create(head,0);
    Display(root);
    return 0;
}
