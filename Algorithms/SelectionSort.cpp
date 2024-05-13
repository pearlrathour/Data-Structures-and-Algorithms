#include<bits/stdc++.h>
using namespace std; 

int selection(vector<int>& a, int n){
    for(int i=0; i<n-1; i++){
        int mn=i;
        for(int j=i+1 ; j<n ; j++){
            if(a[j]<a[mn])
                mn=j;
        }
        if(mn != i)
            swap(a[i],a[mn]);
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    selection(a,n);
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}