// Implement linked list and insert and delete an element into the list

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

void display_linked_list()
{
    Node *temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_front(int val)
{
    Node *node = new Node();
    node->data = val;
    node->next = head;
    head = node;
    display_linked_list();
}


void insert_last(int val){
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
    display_linked_list();
}

void delete_first(){
    if (head == NULL)
    {
        cout << "The Linked List is EMPTY" << endl;
    }
    else if (head->next==NULL)
    {
        head=NULL;
        display_linked_list();
    }
    else
    {
        head=head->next;
        display_linked_list();
    }
}

void delete_last(){
    if (head == NULL)
    {
        cout << "The Linked List is EMPTY" << endl;
    }
    else if(head->next==NULL)
    {
        head = NULL;
        display_linked_list();
    }
    else
    {
        Node *temp=head;
        Node *ptr=head->next;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = NULL;
        display_linked_list();
    }
}

void insert_atK(int val, int k){
    Node *node = new Node();
    Node *temp = head;
    if (k == 1)
    {
        insert_front(val);
        return;
    }
    int j = 1;
    while (j < k -1)
    {
        temp = temp->next;
        j++;
    }
}

void delete_atK(int k){
    if (head == NULL)
    {
        cout << "The Linked List is EMPTY" << endl;
        return;
    }

    if (k == 1)
    {
        delete_first();
        return;
    }

    Node *temp = head;
    int j = 1;
    while (j <k-1)
    {
        temp = temp->next;
        j++;
    }
    display_linked_list();
}


int main()
{

    int usrchoice=0;
    int val, k;
    head = new Node;
    cout << "Enter the value of head" << endl;
    cin >> head->data;
    head->next = NULL;

    while (1){
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
            insert_front(val);
            break;

        case 2:
            cout << "Enter Value to be entered" << endl;
            cin >> val;
            insert_last(val);
            break;

        case 3:
            delete_first();
            break;

        case 4:
            delete_last();
            break;

        case 5:
            cout << "Enter Value to be entered" << endl;
            cin >> val;
            cout << "Enter Value of kth position" << endl;
            cin >> k;
            insert_atK(val, k);
            break;

        case 6:
            cout << "Enter Value of kth position" << endl;
            cin >> k;
            delete_atK(k);
            break;

        case 7:
            exit(1);
        }
    }

    return 0;
}