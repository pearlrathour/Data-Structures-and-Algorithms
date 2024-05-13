#include <bits/stdc++.h>
#define print(a)for (auto x : a)cout << x << ' ';cout<<endl;
using namespace std;

void Merge(int l, int m, int r, vector<int>& arr){
    int l1=l, l2=m+1;
    vector<int>temp;
    while(l1<=m && l2<=r){
        if(arr[l1]<=arr[l2])
            temp.push_back(arr[l1++]);
        else
            temp.push_back(arr[l2++]);
    }
    while(l1<=m) temp.push_back(arr[l1++]);
    while(l2<=r) temp.push_back(arr[l2++]);
    for(int i=l; i<=r; i++) arr[i]=temp[i-l];
}

void MS(int l, int r, vector<int>& arr){
    if(l>=r) return;
    int mid= (r-l)/2 + l;
    MS(l,mid,arr);
    MS(mid+1,r,arr);
    Merge(l,mid,r,arr);
    print(arr);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    MS(0,n-1,arr);
    print(arr);
    return 0;
}