#include <iostream>
using namespace std;

int top = -1;
int n;
int *arr=new int[n];


//O(1)
void push(int val){
    if (top >= n - 1)
        cout << "Overflow !!!\n\n";
    else{
        top++;
        arr[top]=val;
    }
}


//O(1)
void peep(){
    if (top <= -1)
        cout << "Empty Array !!!\n\n";
    else
        cout<<arr[top];
}


//O(1)
void pop(){
    if (top >=0){
        cout<<arr[top];
        top--;
    }
        
    else
        cout << "Underflow !!!\n\n";

}

void display(){
    if (top >=0){
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i]<<" ";
        }
        cout<<endl;
    }
    else
        cout << "Empty Array !!!\n\n";
}

int main()
{
    cout << "Enter size of array : ";
    cin >> n;
    int choice;
    int val;
    while (1)
    {
        cout << "1.Push\n2.Peep\n3.Pop\n4.Display\n5.Exit";
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice){

        case 1:
            cout<<"Enter val : ";
            cin >> val;
            push(val);
            break;

        case 2:
            peep();
            break;

        case 3:
            pop();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(1);

        default:
            cout << "Enter a valid operation" << endl
                 << endl;
            break;
        }
    }
    return 0;
}