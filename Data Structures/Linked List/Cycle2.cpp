// return the node where the cycle begins else NULL

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

Node *Insert(Node *head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->next = NULL;
    return head;
}

void print(Node *head)
{
    Node *curr = head;
    cout << endl
         << endl;
    while (curr != NULL)
    {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl
         << endl;
}

Node *detectCycle(Node *head)
{
    if (!head || !head->next)
        return NULL;

    Node *slow = head, *fast = head, *entry = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    Node *head = NULL;
    int n, val;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter nodes : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        head = Insert(head, val);
    }
    print(head);
    
    cout<<detectCycle(head);
    return 0;
}
