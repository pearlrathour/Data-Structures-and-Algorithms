#include <bits/stdc++.h>
using namespace std;

void Heapify(int i, int n, vector<int>& arr){
    int parent = (i - 1) / 2;
    if (parent >= 0) { 
        // For Max-Heap 
        // If current node is greater than its parent 
        // Swap both of them and call heapify again 
        // for the parent 
        if (arr[i] > arr[parent]) { 
            swap(arr[i], arr[parent]); 
            // Recursively heapify the parent node 
            Heapify(parent,n,arr); 
        } 
    } 
}

void insert(int n, int val, vector<int>& arr){
    n++;
    arr[n-1]=val;
    int i=n-1;
    while(i>=0 && arr[(i-1)/2]<arr[i]){
        swap(arr[i], arr[(i-1)/2]);
        i=(i-1)/2;
    }
}

int main(){
    int n, val;
    cin>>n>>val;
    vector<int>arr(n+1);
    for(int i=0; i<n; i++) cin>>arr[i];
    insert(n,val,arr);
    for(int i=0; i<n+1; i++) cout<<arr[i]<<" ";
    return 0;
}