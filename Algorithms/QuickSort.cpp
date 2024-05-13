#include <bits/stdc++.h>
#define print(a)for (auto x : a)cout << x << ' ';cout<<endl;
using namespace std;

int findpivot(int l, int r, vector<int>& arr){
    int pivot= arr[l];
    int i=l , j=r;
    while(i<j){
        while(arr[i]<=pivot && i<=r-1) i++;
        while(arr[j]>pivot && j>=l+1) j--;
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void QS(int l, int r, vector<int>& arr){
    if(l<r){
        int idx= findpivot(l,r,arr);
        QS(l,idx-1,arr);
        QS(idx+1,r,arr);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    QS(0,n-1,arr);
    print(arr);
    return 0;
}