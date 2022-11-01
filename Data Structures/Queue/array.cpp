#include<iostream>
using namespace std;
int n;
int front=0,rear=0;
int *arr=new int(n);

void Enqueue(int val){
    if(rear >= n){
        cout<<"Overflow"<<endl;
        return;
    }
    arr[rear]=val;
    rear++;
}

void Dequeue(){
    if(front==rear){
        cout<<"Underflow"<<endl;
        return;
    }
    cout<<arr[front]<<endl;
    for (int i=front;i<rear-1;i++) {
        arr[i] = arr[i + 1];
    }
    rear--;
}

void Display(){
    if (front==rear){
        cout << "Empty Array !!!\n\n";
        return;
    }
    for (int i = front; i <rear ; i++)
        cout << arr[i]<<" ";
    cout<<endl;      
}

int main(){
    cout << "Enter size of array : ";
    cin >> n;
    int choice;
    int val;
    while (1){
        cout << "1.Enqueue 2.Dequeue 3.Display 4.Exit";
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice){

        case 1:
            cout<<"Enter val : ";
            cin >> val;
            Enqueue(val);
            Display();
            break;

        case 2:
            Dequeue();
            Display();
            break;
        
        case 3:
            Display();
            break;

        case 4:
            exit(1);

        default:
            cout << "Enter a valid operation" << endl<< endl;
            break;
        }
    }
    return 0;
}