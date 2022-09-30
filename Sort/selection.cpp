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
    int a[]={9,4,0,1,2,8};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<selection(a,n)<<endl;
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}