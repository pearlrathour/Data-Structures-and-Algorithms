#include <bits/stdc++.h>
using namespace std;

void Heapify(int i, int n, vector<int>& arr){
    int l=2*i+1, r= 2*i+2;
    int largest=i;
    if(l<=n && arr[l]>arr[largest])
        largest=l;
    if(r<=n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i){
        swap(arr[i], arr[largest]);
        Heapify(largest,n,arr);
    }
}

void deletemax(int n, vector<int>& arr){
    int mx= arr[0];
    arr[0]=arr[n-1];
    n--;
    Heapify(0,n,arr);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    deletemax(n,arr);
    for(int i=0; i<n-1; i++) cout<<arr[i]<<" ";
    return 0;
}