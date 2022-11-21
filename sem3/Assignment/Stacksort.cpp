#include<bits/stdc++.h>
using namespace std;

stack<int> insertionSort(stack<int> S, int n){
    stack<int> tmp;
    while(!S.empty()){
        int val=S.top();
        S.pop();

        while(!tmp.empty() && tmp.top()<val){
            S.push(tmp.top());
            tmp.pop();
        }
        tmp.push(val);
    }
    return tmp;
}

int main(){
    stack<int> S;
    int val;
    cout<<"Enter values in stack : "<<endl;
    for (int i=0;i<5;i++){
        cin>>val;
        S.push(val);
    }

    stack<int>tmpStack=insertionSort(S,5);
    cout << "Sorted numbers are:\n";
 
    while (!tmpStack.empty())
    {
        cout << tmpStack.top()<< " ";
        tmpStack.pop();
    }
    return 1;
}