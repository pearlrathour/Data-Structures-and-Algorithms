#include<iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node *next;

    Node(int x , int p){
        data=x;
        priority=p;
        next=NULL;
    }
}

Node *head=NULL;

//O(n)
Node* push(Node *head, int x, int p){
    Node *temp=new Node(x,p);
    Node *curr=head;
    if(head == NULL){
        return temp;
    }
    if(head->priority < p){
        temp->next=head;
        return temp;
    }
    else{
        while(curr->next != NULL && curr->next->prioriy > p)
            curr=curr->next;
        
        temp->next=curr->next;
        curr->next=temp;
    }
    return head;
}

//O(1)
int peek(Node *head){
    return head->data;
}

//O(1)
Node* pop(Node *head){
    if(head == NULL)
        return NULL;
    else if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr=head;
    head=curr->next;
    delete curr;
    return head; 
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
    int val, p;

    while (1){
        cout << "\n\n1.Display\n2.Insert\n3.Delete\n4.Peek\n5.Exit"<< endl;
        cout << "Enter the choice of operation to be implemented : ";
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            cout<<"Queue : ";
            display(head);
            break;

        case 2:
            cout <<"Enter Value to be entered : " << endl;
            cin >> val;
            cout <<"Enter priority : " << endl;
            cin >> p;
            head=push(head,val,p);
            display(head);
            break;

        case 3:
            head=pop(head);
            display(head);
            break;

        case 4:
            peek(head);
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