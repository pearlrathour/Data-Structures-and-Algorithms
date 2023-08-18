//Implimenttaion of queue using Linked List

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

void peep(Node *head){
    if(head == NULL){
        cout<<"NULL"<<endl;
        return;
    }
    else if(head->next== NULL){
        cout<<head<<endl;
        return;
    }
    Node *curr=head;
    while(curr->next != NULL){
        curr=curr->next;
    }
    cout<<curr->data<<endl; 
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
    int usrchoice=0;
    int val, k;

    while (1){
        cout << "\n\n1.Display\n2.Push\n3.Peep\n4.Pop\n5.Exit\n"<< endl;
        cout << "Enter the choice of operation to be implemented : ";
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            cout<<"Stack : ";
            display(head);
            break;

        case 2:
            cout <<"Enter Value to be entered" << endl;
            cin >> val;
            head=push(head,val);
            display(head);
            break;

        case 3:
            peep(head);
            break;

        case 4:
            head=pop(head);
            display(head);
            break;

        case 5:
             exit(1);

        default:
            cout<<"Enter a valid choice : ";
            break;
           
        }
    }
    return 0;
}