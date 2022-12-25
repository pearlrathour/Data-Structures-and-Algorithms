#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&A,int temp){
    if(A.size()==0 || A.top() <= temp){
        A.push(temp);
        return;
    }
    int val=A.top();
    A.pop();
    insert(A,temp);
    A.push(val);
}

void sort(stack<int>&A){
    if(A.size()==1)
        return;
    int temp=A.top();
    A.pop();
    sort(A);
    insert(A,temp);
}

int main(){
    int n,a;
    cin>>n;
    stack<int>A;
    for(int i=0;i<n;i++){
        cin>>a;
        A.push(a);
    }
    sort(A);
    for(int i=0;i<n;i++){
        cout<<A.top()<<" ";
        A.pop();
    }
    return 0;
}