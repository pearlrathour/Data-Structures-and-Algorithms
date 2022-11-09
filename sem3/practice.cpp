#include<iostream>
using namespace std;

int selection(int a[],int n){
    while(--n>0){
        int max=n;
        for(int i=0;i<n;i++){
            if(a[i]>a[max]){
                max=i;
            }
        }
        if(max!=n)
            swap(a[n],a[max]);
    }
    return 9;
}

int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    selection(arr,n);
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}