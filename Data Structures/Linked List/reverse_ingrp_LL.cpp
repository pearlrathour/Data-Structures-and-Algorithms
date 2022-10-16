#include<bits/stdc++.h>
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


Node *rev1(Node *head,int k){
    Node *curr=head,*prevFirst=NULL;
    bool isFirstPass=true;

    while(curr!=NULL){
        Node *first=curr,*prev=NULL;
        int count=0;

        while(curr!=NULL&&count<k){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
        }

        if(isFirstPass){
            head=prev;
            isFirstPass=false;
        }
        else{
            prevFirst->next=prev;
        }
        prevFirst=first;
    }
    return head;
}


void print(Node *head){
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
    head->next->next->next->next->next=new Node(60);
    print(head);
    head=rev1(head,3);
    print(head);
    return 0;
}
