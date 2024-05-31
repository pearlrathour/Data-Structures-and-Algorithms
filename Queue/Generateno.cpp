//generate first n numbers with given digits in sorted order
#include<bits/stdc++.h>
using namespace std;

void gen(int dig[],int n,int k){
    queue<string>q;
    for(int i=0;i<n;i++)
        q.push(to_string(dig[i]));
    while(k--){
        cout<<q.front()<<"  ";
        for(int i=0;i<n;i++)
            q.push(q.front() + to_string(dig[i]));
        q.pop();
    }
}

int main(){
    int n,k,digits[n];
    cout<<"No. of digits  : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter no. : ";
        cin>>digits[i];
    }
    cout<<"Enter k : ";
    cin>>k;
    gen(digits,n,k);
    return 0;
}