#include<iostream>
using namespace std;

struct Node{
    int data;
    //self referential structure(address of next node)
    Node *next;

    //constructor to initialise value
    Node(int x){
        data=x;
        next=NULL;
    }
};

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

void print1(Node *head){
    Node *curr=head;
    while(curr != NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

 
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next=new Node(40);
    head=sortedinserting(head,100);
    print1(head);
    return 0;
}