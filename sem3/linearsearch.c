#include<stdio.h>
int linearSearch(int A[],int n,int X){
    for(int i=0;i<n;i++){
        if(A[i]==X){
            return 1;
        }
    }
    // if(i==(n+1))
    return -1;
}
int main(){
    int A[8]={5,22,88,0,12,56,89,54};
    printf("%d",linearSearch(A[],8,56));
    return 0;
}