// Remove Zero Sum Consecutive Nodes from Linked List

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *next;
    int val;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}

    Node* removeZeroSumSublists(Node* head) {
        Node node= Node(0,head);
        unordered_map<int,Node*>ump;
        int pref=0;
        for(Node* ptr=&node; ptr; ptr=ptr->next){
            pref+=ptr->val;
            ump[pref]=ptr;
        }
        pref=0;
        for(Node* ptr=&node; ptr; ptr=ptr->next){
            pref+=ptr->val;
            ptr->next=ump[pref]->next;
        }
        return node.next;
    }


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
};

 
int main(){
    Node *head=NULL;
    int n,val;
    cout<<"Enter n: ";
    cin>>n;
    Node list;
    cout<<"Enter nodes in List: \n";
    for(int i=0; i<n; i++){
        cin>>val;
        head=list.Insert(head,val);
    }
    list.print(head);
    Node* res=list.removeZeroSumSublists(head);
    list.print(res);
    return 0;
}
