#include<bits/stdc++.h>
using namespace std;

class twostacks{
    int *arr;
    int size;
    int top1,top2;

    public:
    //Constructor
    twostacks(int n){
        size=n;
        top1=-1;
        top2=n; 
        arr=new int[n];
    }

    int push1(int val){
        if(top1<top2-1){
            top1++;
            arr[top1]=val;
        }
        else{
            cout<<"Stack Overflow "<<endl;
            return 0;
        }
    }

    int push2(int val){
        if(top1<top2-1){
            top2--;
            arr[top2]=val;
        }
        else{
            cout<<"Stack Overflow "<<endl;
            return 0;
        }
    }

    int pop1(){
        if(top1>=0){
            int x=arr[top1];
            top1--;
            return x;
        }
        else{
            cout<<"Stack Underflow "<<endl;
            return -1; 
        }
    }

    int pop2(){
        if(top2<size){
            int x=arr[top2];
            top2++;
            return x;
        }
        else{
            cout<<"Stack Underflow "<<endl;
            return -1; 
        }
    }

    void display(){
        for(int i=0;i<top1;i++)
            cout<<arr[i];
        for(int j=size;j>top2;j--)
            cout<<arr[j];
    }

    bool isFull(){
        if(top1== top2-1)
            return true;
        return false;
    }
};

int main(){
    twostacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    cout<<ts.isFull()<<endl;
    ts.push2(7);
    cout << "Popped element from stack1 is "<< ": " << ts.pop1() << endl;
    ts.push2(40);
    cout<<ts.isFull()<<endl;
    cout << "Popped element from stack2 is "<< ": " << ts.pop2() << endl;
    cout<<ts.isFull()<<endl;
    return 0;
}