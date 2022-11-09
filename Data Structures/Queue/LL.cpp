#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    //constructor to initialise value
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node *rear=NULL,*front=NULL;

//O(1)
Node *Enqueue(Node *rear,int val){
    Node *temp=new Node(val);
    if(rear==NULL){
       temp->next=rear;
       front=rear=temp;
       return temp; 
    }
    
    Node *curr=rear;
    curr->next=temp;
    temp->next=NULL;
    return temp;
}

//O(1)
Node *Dequeue(Node *front){
    if(front == NULL)
        return NULL;
    else if(front->next == NULL){
        delete front;
        return NULL;
    }
    Node *curr=front;
    front=curr->next;
    delete curr;
    return front; 
}

//O(n)
void display(Node *front){
    Node *curr=front;
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
        cout << "\n\n1.Display\n2.Insert\n3.Delete\n4.Exit\n"<< endl;
        cout << "Enter the choice of operation to be implemented : ";
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            cout<<"Queue : ";
            display(front);
            break;

        case 2:
            cout <<"Enter Value to be entered" << endl;
            cin >> val;
            rear=Enqueue(rear,val);
            display(front);
            break;

        case 3:
            front=Dequeue(front);
            display(front);
            break;

        case 4:
             exit(1);

        default:
            cout<<"Enter a valid choice : ";
            break;
           
        }
    }
    return 0;
}