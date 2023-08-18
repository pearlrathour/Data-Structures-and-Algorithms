#include <iostream>
using namespace std;

struct Node
{
    int val;
    // self referential structure(address of next node)
    Node *next;

    // constructor to initialise value
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

Node *removeNthFromEnd(Node *head, int n)
{
    Node *start;
    start->next = head;
    Node *fast = start;
    Node *slow = start;

    for (int i = 1; i <= n; ++i)
        fast = fast->next;

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return start->next;
}

void print1(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    print1(head);
    Node* ans=removeNthFromEnd(head,3);
    print1(ans);
    return 0;
}