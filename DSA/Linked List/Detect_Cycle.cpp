#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    //constructor to initialise value
    Node(int x){
        data=x;
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
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl<<endl;
}

//Tortoise Hare Algo
bool hasCycle(Node *head) {
        if(!head)
            return 0;
        Node* slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast->next==slow)
                return 1;
        }
        return 0;
    }
 
int main(){
    Node *head=NULL;
    int n,val;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter nodes : \n";
    for(int i=0; i<n; i++){
        cin >> val;
        head=Insert(head,val);
    }
    print(head);
    cout<<hasCycle(head);
    return 0;
}
