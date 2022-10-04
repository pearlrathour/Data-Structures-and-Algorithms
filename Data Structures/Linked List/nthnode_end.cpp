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

void printend(Node *head , int n){
    if(head==NULL)
        return;
    Node *curr;
    int len=0;

    for(curr=head ; curr !=NULL ; curr=curr->next)
        len++;

    if(len<n)
        return;
    
    curr=head;
    // for(int i=len ; i>n ; i--)
    for(int i=0; i<len-n ; i++)
        curr=curr->next;
    cout<<curr->data<<endl;
}


void printend1(Node *head , int n){
    if(head==NULL)
        return;
    Node * first=head, *second=head;
    while(n){
        second=second->next;
        n--;
    }
    while(second){
        first=first->next;
        second=second->next;
    }
    cout<<first->data<<endl;
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
    head->next->next->next->next=new Node(50);
    print1(head);
    printend(head,2);
    printend1(head,2);
    return 0;
}