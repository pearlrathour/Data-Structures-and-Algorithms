#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;

    //constructor to initialise value
    Node(int x){
        val=x;
        next=NULL;
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

int getDecimalValue(Node* head) {
    int ans=0;
    while(head != NULL){
        ans=ans*2 + head->val;
        head=head->next;
    }
    return ans;
}
 
int main(){
    Node *head=NULL;
    int n,val;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter nodes in List: \n";
    for(int i=0; i<n; i++){
        cin >> val;
        head=Insert(head,val);
    }
    print(head);

    cout<<getDecimalValue(head)<<endl;    
    return 0;
}
