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

Node *rev(Node *head){
    Node *curr=head , *prev=NULL ,*next=NULL;
    while(curr != NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}


void comp(Node *head,Node *head1){
    Node *curr=head,*curr1=head1;
    while(curr != NULL && curr1 !=NULL){
        if(curr->data == curr1->data){
            curr=curr->next;
            curr1=curr1->next;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

bool isPalindrome(Node *head){
    stack<char> st;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        st.push(curr->data);
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        if(st.top()!=curr->data)
            return false;
        st.pop();
    }
    return true;
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
    head->next->next->next=new Node(20);
    head->next->next->next->next=new Node(10);
    Node *head1=rev(head);
    print(head1);
    comp(head,head1);
    return 0;
}
