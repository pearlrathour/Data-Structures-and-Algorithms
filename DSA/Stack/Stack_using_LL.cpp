//Implimenttaion of queue using Linked List

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x){
        data=x;
        next=NULL;
    }
};

Node *head=NULL;

void push(Node *head, int val){
    Node *temp=new Node(val);
    temp->next= head;
    head= temp;
    cout<<head->data;
}


int pop(Node *head){
    if(head == NULL) return -1;
    int t= head->data;
    head= head->next;
    return t;
}

int peep(Node *head){
    if(head == NULL) return -1;
    return head->data; 
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
            cout <<"Enter Value to be entered : ";
            cin >> val;
            display(head);
            break;

        case 3:
            cout<<peep(head)<<endl;
            break;

        case 4:
            cout<<pop(head)<<endl;
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