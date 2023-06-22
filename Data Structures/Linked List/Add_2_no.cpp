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

Node* addTwoNumbers(Node* l1, Node* l2) {
        Node *ans, *temp=ans;
        int carry=0;

        while(l1 || l2 || carry){
            int sum = 0; 
            if(l1) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            temp->next = new Node(sum % 10);  
            temp = temp -> next; 
        }
        return ans->next;
    }
 
int main(){
    Node *head1=NULL, *head2=NULL;
    int n1,n2,val;
    cout<<"Enter n1, n2 : ";
    cin>>n1>>n2;
    cout<<"Enter nodes in List1: \n";
    for(int i=0; i<n1; i++){
        cin >> val;
        head1=Insert(head1,val);
    }
    cout<<"Enter nodes in List2: \n";
    for(int i=0; i<n2; i++){
        cin >> val;
        head2=Insert(head2,val);
    }
    print(head1);
    print(head2);

    Node *res=addTwoNumbers(head1,head2);
    print(res);
    return 0;
}
