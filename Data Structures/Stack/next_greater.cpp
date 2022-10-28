#include<bits/stdc++.h>
using namespace std;

//O(n**2)
void next1(int arr[],int n){
    for(int i=0;i<n;i++){
        int m=-1;
        for(int j=i+1;j<n;j++){
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
void next2(int arr[],int n){
    vector<int> v;
    stack<int>s;
    s.push(arr[n-1]);
    v.push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        int ng=s.empty()?-1:s.top();
        v.push_back(ng);
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}




int main(){
    int arr[]={18,12,10,9,6,7,15};
    next1(arr,7);
    next2(arr,7);
    return 1;
}