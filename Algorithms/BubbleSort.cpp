#include<iostream>
using namespace std;

void bubblesort(int a[],int n){
    bool flag=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);      
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    if (flag==0)
        cout<<"Already sorted array";
    else
        for(int i=0 ; i<n ; i++)
        cout<<a[i]<<" ";
}

int main(){
    int a[]={3,2,1,4};
    int n=sizeof(a)/sizeof(a[0]);
    bubblesort(a,n);
    return 0;
}