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

Node *sortedmerge(Node *head1 , Node *head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    Node *head=NULL,*tail=NULL;
    if(head1->data <= head2->data){
        head=tail=head1;
        head1=head1->next;
    }
    else{
        head=tail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            tail->next=head1;
            tail=head1;
            head1=head1->next;
        }
        else{
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
    }
    if(head1==NULL){
        tail->next=head2;
    }
    else{
        tail->next=head1;
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
    Node *head1=new Node(10);
    head1->next = new Node(40);
    head1->next->next=new Node(50);
    head1->next->next->next=new Node(70);
    head1->next->next->next->next=new Node(100);
    cout<<"1st Linked List : \n";
    print(head1);

    Node *head2=new Node(0);
    head2->next = new Node(20);
    head2->next->next=new Node(60);
    head2->next->next->next=new Node(80);
    head2->next->next->next=new Node(110);
    cout<<"2nd Linked List : \n";
    print(head2);
    
    print(sortedmerge(head1,head2));
    return 0;
}
