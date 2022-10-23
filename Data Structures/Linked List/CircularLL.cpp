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


Node *Insertbegin(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL)
        temp->next=temp;
    else{
        // Node *curr=head;
        // while(curr->next != head)
        //     curr=curr->next;
        // curr->next=temp;
        // temp->next=head;

        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
    return temp;
}


Node *Insertend(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL){
       temp->next=head;
       return temp; 
    }
    
    // else{
    // Node *curr=head;
    // while(curr->next != NULL)
    //     curr=curr->next;
    // curr->next=temp;
    // temp->next=head;
    // return head;
    // }

    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return temp;
    }
}


Node *Deletefirst(Node *head){
    if(head==NULL)
        return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=head->next;
    delete head;
    return (curr->next);

    // head->data=head->next->data;
    // Node *temp=head->next;
    // head->next=head->next->next;
    // delete temp;
    // return head;
}

Node *Deleteend(Node *head){
    
}


void print(Node *head){
    if(head==NULL)
        return;
    Node *curr=head;
    do{
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    while(curr != head);
    cout<<endl;
}

int main(){
    Node *head=NULL;

    int usrchoice=0;
    int val, k;

    while (1){
        cout << "\n\n1.Insert at Beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Display\n6.Exit\n"<< endl;
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
            exit(1);

        default:
            cout<<"Enter a valid choice : ";
            break;
           
        }
    }
    return 0;
}