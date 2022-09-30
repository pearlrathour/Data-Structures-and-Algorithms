#include<iostream.h>
uisng namespace std;

void insert(int A[],int n,int k,int item){
    int j=n;
    while(j>=k){
        A[j+1]=A[j];
        j=j-1;
    }
    A[k]=item;
    n=n+1;
}