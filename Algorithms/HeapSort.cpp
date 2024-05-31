#include<bits/stdc++.h>
using namespace std;

//O(nlogn)
void Heapify(int i, int n, vector<int>& arr){
    int l=2*i+1, r= 2*i+2;
    int largest=i;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i){
        swap(arr[i], arr[largest]);
        Heapify(largest,n,arr);
    }
}


void HeapSort(vector<int>& arr,int n){
    for (int i= (n/2)-1; i>=0; i--)
        Heapify(i,n,arr);
 
    // One by one extract an element from heap
    for (int i= n-1; i>0; i--) {
        // Move current root to end(Deletion)
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        Heapify(0,i,arr);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];
    HeapSort(arr,n);
    cout<<"HeapSort : "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}