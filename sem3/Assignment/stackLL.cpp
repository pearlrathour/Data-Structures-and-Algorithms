#include <iostream>
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

Node *head=NULL;

Node *push(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL){
        temp->next=NULL;
        return temp; 
    }
    Node *curr=head;
    while(curr->next != NULL)
        curr=curr->next;
    curr->next=temp;
    temp->next=NULL;
    return head;
}


Node *pop(Node *head){
    if(head == NULL)
        return NULL;
    else if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next->next != NULL){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
    return head; 
}

Node *clearstack(Node *head){
    Node *curr=head,*prev;
    while(curr->next!= NULL){
        prev=curr;
        curr=curr->next;
        delete prev;
    }
    delete curr;
    return head;  
}

void display(Node *head){
    Node *curr=head;
    while(curr != NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    head=push(head,10);
    head=push(head,40);
    head=push(head,20);
    head=push(head,30);
    display(head);
    head=pop(head);
    display(head);
    head=clearstack(head);
    display(head);
    return 0;
}