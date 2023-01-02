#include<bits/stdc++.h>
using namespace std;

int firstocc(int arr[], int n, int val){
    int low=0;
    int high=n-1;
    int res=-1;
    while(low <= high){
        int mid=(low+high)/2;

        if(arr[mid]<val)
            low=mid+1;
        else if(arr[mid]>val)
            high=mid-1;
        else{
            res=mid;
            high=mid-1;
        }
    }
    return res;
}

int lastocc(int arr[], int n, int val){
    int low=0;
    int high=n-1;
    int res=-1;
    while(low <= high){
        int mid=(low+high)/2;

        if(arr[mid]<val)
            low=mid+1;
        else if(arr[mid]>val)
            high=mid-1;
        else{
            res=mid;
            low=mid+1;
        }
    }
    return res;
}

int main(){
    int n,val;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cin>>val;
    int f=firstocc(arr,n,val);
    int l=lastocc(arr,n,val);
    if(f==-1 && l==-1)
        cout<<0<<endl;
    else
        cout<<l-f+1<<endl;
    return 9;
}