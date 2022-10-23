#include <iostream>
using namespace std;

struct Node{
    int data;
    //self referential structure(address of next node)
    Node *prev;
    Node *next;

    //constructor to initialise value
    Node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};


Node *Insertbegin(Node *head,int val){
    Node *temp=new Node(val);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}


Node *Insertend(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;
}


Node *Deletefirst(Node *head){
    if(head == NULL)
        return NULL;
    Node *temp=head->next;
    delete head;
    return temp; 
}

Node *Deleteend(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next->next != NULL)
        curr=curr->next;
    delete curr->next;
    curr->next=NULL;
    return head;
}


void print(Node *head){
    Node *curr=head;
    cout<<"NULL <-> ";
    while(curr!=NULL){
        cout<<curr->data<<" <-> ";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

Node *reverse(Node *head){
    if(head==NULL && head->next ==NULL)
        return head;
    Node *prev=NULL,*curr=head;
    while(curr!=NULL){
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev->prev;
}

int main(){
    Node *head=NULL;

    int usrchoice=0;
    int val, k;

    while (1){
        cout << "\n\n1.Insert at Beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Display\n6.Reverse\n7.Exit\n"<< endl;
        cout << "Enter the choice of operation to be implemented : ";
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            cout <<"Enter Value to be entered" << endl;
            cin >> val;
            head=Insertbegin(head,val);
            print(head);
            break;

        case 2:
            cout << "Enter Value to be entered : ";
            cin >> val;
            head=Insertend(head,val);
            print(head);
            break;

        case 3:
            head=Deletefirst(head);
            print(head);
            break;

        case 4:
            head=Deleteend(head);
            print(head);
            break;

        case 5:
            print(head);
            break;

        case 6:
            head=reverse(head);
            print(head);
            break;

        case 7:
             exit(1);

        default:
            cout<<"Enter a valid choice : ";
            break;
           
        }
    }
    return 0;
}