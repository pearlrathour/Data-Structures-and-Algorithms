#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;   
    Node* next;     
    Node(int v) {
        val = v;
        next = NULL;
    }
};


// TC O(n) SC O(n)
int lengthOfLoop(Node* head) {
    unordered_map<Node*, int> visitedNodes; 
    Node* temp = head; 
    int timer = 0; 
    while (temp != NULL) {
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            int loopLength = timer - visitedNodes[temp];
            return loopLength; 
        }
        visitedNodes[temp] = timer;
        temp = temp->next;
        timer++;
    }
    return 0;
}

//O(n)
int fun(Node* head){
    Node *slow=head, *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast->next==slow) break;
    }
    int l=1;
    while(slow!=fast){
        l++;
        slow=slow->next;
    }
    return l;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; 

    cout << "Length of the loop: " << fun(head) << endl;

    return 0;
}


