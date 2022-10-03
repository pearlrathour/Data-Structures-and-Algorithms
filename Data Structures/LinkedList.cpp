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

int Search(Node *head , int val){
    int pos=1;
    Node *curr=head;
    while(curr!=NULL){
        if(curr->data==val)
            return pos;
        pos++;
        curr=curr->next;
    }
    return -1;
}

Node *Insertbegin(Node *head,int val){
    Node *temp=new Node(val);
    temp->next=head;
    return temp;
}


Node *Insertend(Node *head,int val){
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

Node *Insertatk(Node *head,int k,int val){
    Node *temp=new Node(val);    
    if(k==1){
        temp->next=head;
        return temp;
    }

    Node *curr=head;
    for(int i=1 ; i<=k-2 && curr!=NULL ; i++){
        curr=curr->next;
    }

    if (curr==NULL)
        return head;
    
    temp->next=curr->next;
    curr->next=temp;
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
    else if(head->next == NULL){
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
    while(curr != NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node *head=NULL;

    int usrchoice=0;
    int val, k;

    while (1){
        cout << "\n\n1.Search\n2.Insert at Beginning\n3.Insert at end\n4.Insert at a position\n5.Delete from beginning\n6.Delete from end\n7.Display\n8.Exit\n"<< endl;
        cout << "Enter the choice of operation to be implemented : ";
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            cout <<"Enter Value to be searched : " << endl;
            cin >> val;
            cout<<val<<" is at position : "<<Search(head,val)<<endl;
            break;

        case 2:
            cout <<"Enter Value to be entered" << endl;
            cin >> val;
            head=Insertbegin(head,val);
            print(head);
            break;

        case 3:
            cout << "Enter Value to be entered : ";
            cin >> val;
            head=Insertend(head,val);
            print(head);
            break;

        case 4:
            cout << "Enter Value to be entered : ";
            cin >> val;
            cout<<"Enter position : ";
            cin>>k;
            head=Insertatk(head,k,val);
            print(head);
            break;

        case 5:
            head=Deletefirst(head);
            print(head);
            break;

        case 6:
            head=Deleteend(head);
            print(head);
            break;

        case 7:
            print(head);
            break;

        case 8:
             exit(1);

        default:
            cout<<"Enter a valid choice : ";
            break;
           
        }
    }
    return 0;
}