#include<bits/stdc++.h>
using namespace std;

//O(n**2)
void prev1(int arr[],int n){
    for(int i=0;i<n;i++){
        int m=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                m=arr[j];
                break;
            }
        }
        cout<<m<<" ";
    }
    cout<<endl;
}

//O(n)
void prev2(int arr[],int n){
    stack<int>s;
    s.push(arr[0]);
    for(int i=0;i<n;i++){
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        int m=s.empty()?-1:s.top();
        cout<<m<<" ";
        s.push(arr[i]);
    }
}

int main(){
    int arr[]={18,12,10,9,6,7,15};
    prev1(arr,7);
    prev2(arr,7);
    return 1;
}