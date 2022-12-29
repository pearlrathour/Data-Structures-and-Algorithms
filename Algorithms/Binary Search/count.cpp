#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int val){
    int low=0;
    int high=n-1;
    while(low <= high){
        int mid=(low+high)/2;

        if(arr[mid]<val)
            low=mid+1;
        else if(arr[mid]>val)
            high=mid-1;
        else
            return mid;
    }
    return -1;
}

int occ(int arr[],int n,int val){
    int i=BinarySearch(arr,n,val);

    if(i==-1)
        return 0;

    int count=1;
    int left=i-1;

    while(left>=0 && arr[left]==val){
        count++;
        left--;
    }

    int right=i+1;
    while(right<n && arr[right]==val){
        count++;
        right++;
    }
    return count;
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
    cout<<occ<<endl;
    return 1;
}