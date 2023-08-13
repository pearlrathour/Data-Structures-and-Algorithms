// Implement linked list and insert and delete an element into the list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *head = new Node();
void displayLinkedList()
{
    Node *temp = new Node();
    temp = head;
    cout << endl;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertfront(int val)
{
    Node *node = new Node();
    node->data = val;
    node->next = head;
    head = node;

    displayLinkedList();
}

void insertLast(int val)
{
    Node *temp = head;
    if (head == NULL)
    {
        Node *node = new Node();
        node->data = val;
        node->next = NULL;
        head = node;
    }

    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node *node = new Node();
        node->data = val;
        node->next = NULL;
        temp->next = node;
    }
    displayLinkedList();
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "The Linked List is EMPTY" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        displayLinkedList();
    }
    else
    {
        head = head->next;
        displayLinkedList();
    }
}

void deleteLast()
{
    if (head == NULL)
    {
        cout << "The Linked List is EMPTY" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        displayLinkedList();
    }
    else
    {

        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        displayLinkedList();
    }
}

void insertAtK(int val, int k)
{
    Node *node = new Node();
    Node *temp = head;
    if (k == 1)
    {
        insertfront(val);
        return;
    }
    int j = 1;

    while (j <= k - 2)
    {
        temp = temp->next;
        j++;
    }

    node->next = temp->next;
    node->data = val;
    temp->next = node;

    displayLinkedList();
}

void deleteAtK(int k)
{
     if (head == NULL)
    {
        cout << "The Linked List is EMPTY" << endl;
        return;
    }
    if (k == 1)
    {
        deleteFirst();
        return;
    }

    Node *temp = head;
    int j = 1;

    while (j <= k - 2)
    {
        temp = temp->next;
        j++;
    }
    temp->next = temp->next->next;

    displayLinkedList();
}

int main()
{

    int usrchoice = 0;
    int val, k;

    cout << "Enter the value of head" << endl;
    cin >> head->data;
    head->next = NULL;

    while (1)
    {
        cout << "\n\nEnter\n 1.Insert Node at the front\n2.Insert Node at the last\n3.Delete the first Node\n4.Delete the last Node\n5.Insert at Kth position\n6.Delete at the kth position\n7.Exit\n\n"
             << endl;

        cout << "Enter the choice of operation to be implemented\n\n"
             << endl;
        cin >> usrchoice;

        switch (usrchoice)
        {
        case 1:
            cout << "Enter Value to be entered" << endl;
            cin >> val;
            insertfront(val);
            break;

        case 2:
            cout << "Enter Value to be entered" << endl;
            cin >> val;
            insertLast(val);
            break;

        case 3:
            deleteFirst();
            break;

        case 4:
            deleteLast();
            break;

        case 5:
            cout << "Enter Value to be entered" << endl;
            cin >> val;
            cout << "Enter Value of kth position" << endl;
            cin >> k;
            insertAtK(val, k);
            break;

        case 6:
            cout << "Enter Value of kth position" << endl;
            cin >> k;
            deleteAtK(k);
            break;

        case 7:
            exit(1);
        }
    }

    return 0;
}