#include <iostream>
using namespace std;

struct Node{
    int data;
    //self referential structure(address of next node)
    Node *prev;
    Node *next;

    //constructor to initialise value
    Node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};
Node*head=NULL;

Node *Insertend(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;
}

Node *sortedinserting(Node *head,int val){
    Node *temp=new Node(val);    
    Node *curr=head;

    if(head==NULL){
        return temp;
    }

    if((head->data)>val){
        temp->next=head;
        return temp;
    }

    while(curr->next != NULL && curr->next->data <val)
        curr=curr->next;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

void print(Node *head){
    Node *curr=head;
    cout<<"NULL <-> ";
    while(curr!=NULL){
        cout<<curr->data<<" <-> ";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    head=Insertend(head,10);
    head=Insertend(head,20);
    head=Insertend(head,30);
    head=Insertend(head,40);
    head=sortedinserting(head,25);
    print(head);
    return 0;
}