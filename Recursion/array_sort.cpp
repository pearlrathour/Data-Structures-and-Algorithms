#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&A,int temp){
    if(A.size()==0 || A[A.size()-1] <= temp){
        A.push_back(temp);
        return;
    }
    int val=A[A.size()-1];
    A.pop_back();
    insert(A,temp);
    A.push_back(val);
}

void sort(vector<int>&A){
    if(A.size()==1)
        return;
    int temp=A[A.size()-1];
    A.pop_back();
    sort(A);
    insert(A,temp);
}

int main(){
    int n,a;
    cin>>n;
    vector<int>A;
    for(int i=0;i<n;i++){
        cin>>a;
        A.push_back(a);
    }
    sort(A);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}