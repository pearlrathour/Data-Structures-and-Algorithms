#include<iostream>
using namespace std;

int bin(int a[],int n,int val){
    int lb=0;
    int ub=n-1;
    while(lb<=ub){
        int mid=(lb+ub)/2;

        if(a[mid] < val)
            lb=mid+1;

        else if(a[mid] > val)
            ub=mid-1;

        else
            return mid;
    }
    return -1;
}

int rec_bin(int a[],int lb,int ub,int val){
    if(lb<=ub){
        int mid=(lb+ub)/2;
        
        if(a[mid]<val)
            rec_bin(a,mid+1,ub,val);
        
        else if(a[mid]>val)
            rec_bin(a,lb,mid-1,val);
        
        else
            return mid; 
    }
    return -1;
}

int main(){
    int a[]={4,7,10,13,30};
    int n = sizeof(a) / sizeof(a[0]);
    int val=30;
    cout<<bin(a,n,val)<<endl;
    cout<<rec_bin(a,0,n-1,val)<<endl;
    return 0;
}