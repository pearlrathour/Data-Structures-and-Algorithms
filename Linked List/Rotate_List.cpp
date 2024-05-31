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

// Node* rotateRight(Node* head, int k) {
//         if(!head || k==0 || !head->next)
//             return head;

//         for(int i=0; i<k; i++){
//             Node *temp=head;
//             while(temp->next->next != NULL)
//                 temp = temp->next;
//             Node* end = temp->next;
//             temp->next = NULL;
//             end->next = head;
//             head = end;
//         }
//         return head;
//     }

Node *rotateRight(Node *head, int k)
{
    if (!head || k == 0 || !head->next)
        return head;

    Node *temp = head;
    int l = 1;
    while (temp->next)
    {
        temp = temp->next;
        l++;
    }

    temp->next = head;
    k %= l;
    int end = l - k;
    while (end--)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}

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
    cout << "NULL" << endl;
}

int main()
{
    Node *head1 = NULL, *head2 = NULL;
    int n1, k, val;
    cout << "Enter n, k : ";
    cin >> n1 >> k;
    cout << "Enter nodes in List1: \n";
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        head1 = Insert(head1, val);
    }
    print(head1);

    Node *res = rotateRight(head1, k);
    print(res);
    return 0;
}