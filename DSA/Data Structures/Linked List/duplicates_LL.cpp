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

void duplicate(Node *head){    
    Node *curr=head;
    while(curr != NULL && curr->next !=NULL){
        if(curr->data == curr->next->data){
            Node *temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }
        else
            curr=curr->next;
    }
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
    head->next->next=new Node(20);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(40);
    head->next->next->next->next->next=new Node(50);
    duplicate(head);
    print1(head);
    return 0;
}