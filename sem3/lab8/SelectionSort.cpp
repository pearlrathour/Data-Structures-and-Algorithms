#include<iostream>
using namespace std;

void swap(int*x,int*y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
} 

int selection(int a[],int n){
    while(--n>0){
        int max=n;
        for(int i=0 ; i<n ; i++){
            if(a[i]>a[max])
                max=i;
        }
        if(max != n)
            swap(&a[n],&a[max]);
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<selection(arr,n)<<endl;
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}