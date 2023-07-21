#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;

    //constructor to initialise value
    Node(int x){
        val=x;
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
        cout<<curr->val<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

Node *getIntersectionNode(Node *headA, Node *headB) {
        Node *currA=headA, *currB=headB;
        while(currA!=currB){
            if(!currA)
                currA=headB;
            else
                currA=currA->next;

            if(!currB)
                currB=headA;
            else
                currB=currB->next;         
        }
        return currA;
    }
 
int main(){
    Node *head=new Node(2);
    head->next = new Node(4);
    
    Node *head1=new Node(1);
    head1->next = new Node(9);
    head1->next->next=new Node(1);
    head1->next->next->next=head;
    
    Node *head2=new Node(3);
    head2->next->next->next=head;


    print(head1);
    print(head2);

    Node *res=getIntersectionNode(head1,head2);
    cout<<res;
    cout<<res->val;
    return 0;
}
