#include <iostream>
using namespace std;

int queue[100], n = 100, front = -1, rear = -1;

//O(1)
void Insert(int val){
    if (front == -1)
        front = 0;
    if (rear >= n - 1){
        cout << "Queue Overflow" << endl;
        return;
    }
    rear++;
    queue[rear] = val;
}

//O(1)
void Delete(){
    if (front == -1 || front > rear){
        cout << "Queue Underflow ";
        return;
    }
    cout << "Element deleted from queue is : " << queue[front] << endl;
    front++;
}

//O(n)
void Display(){
    if (front == -1){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are : ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

int main(){
    int val;
    int usrchoice=0;
    
    while(1){
        cout << "\n\n1.Insert 2.Delete  3.Display 4.Exit\n"<< endl;
        cout << "Enter the choice of operation to be implemented : ";
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            cout<<"Enter value : ";
            cin>>val;
            Insert(val);
            Display();
            break;
        case 2:
            Delete();
            Display();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid valoice" << endl;
        }
    }
    return 0;
}