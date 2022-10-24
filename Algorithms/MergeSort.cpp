#include<iostream>
using namespace std;

void Merge(int A[],int low,int q,int high){
    int l1=q-low+1;
    int l2=high-q;
    int L[l1],R[l2];
    for(int i=0;i<l1;i++)
        L[i]=A[low+i];
    for(int j=0;j<l2;j++)
        R[j]=A[q+j+1];
    int i=0,j=0;
    for(int k=low;k<high;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
}
void MergeSort(int A[],int low,int high){
    if(low<high){
        int q=(low+high)/2;
        MergeSort(A,low,q);
        MergeSort(A,q+1,high);
        Merge(A,low,q,high);
    }
}

int main(){
	int arr[] = {1000, 11, 445,1, 330, 3000 };
	int size =sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	MergeSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}