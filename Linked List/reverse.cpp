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
    vector<int>arr;
    Node *curr;
    for(curr=head ; curr!=NULL ; curr=curr->next)
        arr.push_back(curr->data);
    for(curr=head ; curr!=NULL ; curr=curr->next){
        curr->data=arr.back();
        arr.pop_back();
    }
    return head;
}

//efficient O(N) O(1)
Node *rev1(Node *head){
    Node *curr=head , *prev=NULL ,*next=NULL;
    while(curr != NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

//Recursive
Node *rev3(Node *head){
    if(head==NULL || head->next ==NULL)
        return NULL;
    Node *rest_head=rev3(head->next);
    Node  *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

// Node *rev4(Node *curr,Node *prev){
//     if(curr==NULL)
//         return prev;
//     Node *next=curr->next;
//     curr->next=prev;
//     return rev4(next,curr);
// }

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
    print(head);
    head=rev(head);
    print(head);
    head=rev1(head);
    print(head);
    head=rev3(head);
    print(head);
    // head=rev4(head);
    // print(head);
    return 0;
}
