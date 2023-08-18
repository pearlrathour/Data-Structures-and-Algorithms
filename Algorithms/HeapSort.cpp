#include<iostream>
using namespace std;

//O(nlogn)
void Heapify(int A[],int n,int i){
    int largest = i; //root
    int l= 2*i + 1; // left child
    int r= 2*i + 2; // right child
 
    if (l < n && A[l] > A[largest])
        largest=l;
 
    if (r < n && A[r] > A[largest])
        largest=r;
 
    if (largest != i){
        swap(A[i],A[largest]);
        // Heapify the affected sub-tree
        Heapify(A,n,largest);
    }
}


void HeapSort(int A[],int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(A, n, i);
 
    // One by one extract an element from heap
    for (int i = n-1; i >= 0; i--) {
        // Move current root to end(Deletion)
        swap(A[0], A[i]);
        // call max heapify on the reduced heap
        Heapify(A, i, 0);
    }
}

int main(){
    int n;
    cout<<"Enter number of nodes in tree : ";
    cin>>n;
    int A[n];
    cout<<"Enter elements : "<<endl;
    for(int i=0 ; i<n ; i++){
        cin>>A[i];
    }
        
    for(int i=0 ; i<n ; i++)
        cout<<A[i]<<" ";
    cout<<endl;
    HeapSort(A,n);
    cout<<"HeapSort : "<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}