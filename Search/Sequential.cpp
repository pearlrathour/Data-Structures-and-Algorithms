#include<iostream>
using namespace std;

int find(int a[],int n,int x){
    for(int i=0 ; i<n ; i++){
        if(a[i]==x)
            return i;
    }
    return -1;
}

int main(){
    int a[5]={4,0,1,8,2};
    int val=9;
    cout<<find(a,5,val);
    return 0;
}