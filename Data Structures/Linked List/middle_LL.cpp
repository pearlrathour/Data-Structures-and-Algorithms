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

void printmiddle(Node *head){
    if(head==NULL)
        return;
    int length=0;
    Node *curr;
    for(curr=head ; curr!=NULL ; curr=curr->next){
        length++;
    }
    
    curr=head;
    for(int i=0; i<length/2 ; i++){
        curr=curr->next;
    }
    cout<<curr->data<<endl;
}


//Efficient function
//slow and fast pointers-slow moves 1 node & fast moves 2 node at a time
void printmiddle1(Node *head){
    if(head==NULL)
        return;
    Node *slow=head , *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
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
    head->next = new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    // head->next->next->next->next=new Node(50);
    print1(head);
    printmiddle(head);
    printmiddle1(head);
    return 0;
}