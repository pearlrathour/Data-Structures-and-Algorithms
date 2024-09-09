#include<bits/stdc++.h>
using namespace std;

void del(stack<int>&A,int n){
    if(A.size()==n){
        A.pop();
        return;
    }
    int temp=A.top();
    A.pop();
    del(A,n);
    A.push(temp);
}

int main(){
    int n,a;
    cin>>n;
    stack<int>A;
    for(int i=0;i<n;i++){
        cin>>a;
        A.push(a);
    }
    del(A,(n/2)+1);
    n=A.size();
    for(int i=0;i<n;i++){
        cout<<A.top()<<" ";
        A.pop();
    }
    return 0;
}